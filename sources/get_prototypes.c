/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prototypes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:48:42 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/28 19:46:46 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	write_prototype(struct s_str *buf, int *swit, int tmp_fd, \
unsigned int *max_distance)
{
	unsigned int	distance;

	distance = is_func_prototype(buf->str);
	if (comment_switch(buf->str, swit, buf->len) || ! distance)
		return (EXIT_SUCCESS);
	*(buf->str + buf->len - 1) = ';';
	tstr_addchar(buf, '\n');
	tstr_addchar(buf, '\n');
	if ((write(tmp_fd, buf->str, buf->len) < 0))
		return (EXIT_FAILURE);
	if (distance > *max_distance)
		*max_distance = distance;
	return (EXIT_SUCCESS);
}

static int	check_errors_and_delete(struct s_str *buf, FILE *fstream)
{
	int	err;

	err = EXIT_SUCCESS;
	if (! feof(fstream))
		err = EXIT_FAILURE;
	fclose(fstream);
	tstr_del(buf);
	return (err);
}

static int	initialize(struct s_str **buf, FILE **fstream, \
const char *filename)
{
	if ((*buf = calloc(1, sizeof **buf)) == NULL)
	{
		dprintf(STDERR_FILENO, \
		"Couldn't allocate struct s_str of size : 1\n");
		return (EXIT_FAILURE);
	}
	if ((*fstream = fopen(filename, "r")) == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Couldn't open file : %s\n", filename);
		tstr_del(*buf);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	get_prototypes_file(const char *filename, int tmp_fd, unsigned int *max_distance)
{
	FILE			*fstream;
	int				swit;
	struct s_str	*buf;
	int				err;

	if (initialize(&buf, &fstream, filename))
		return (EXIT_FAILURE);
	swit = 0;
	while (! get_codeline(&buf, fstream))
	{
		if (write_prototype(buf, &swit, tmp_fd, max_distance))
			break ;
	}
	err = check_errors_and_delete(buf, fstream);
	if (err)
		ft_dprintf(STDERR_FILENO, "Error while dealing with file : %s\n", filename);
	return (EXIT_SUCCESS);
}

static char	*get_filename(void *content)
{
	char	*filename;

	filename = ft_strrchr((char *)content, '/');
	if (! filename)
		return ((char *)content);
	return (filename + 1);
}

unsigned int	get_prototypes(t_list **filenames, const char *tmp_file, unsigned int *max_distance)
{
	char			*filename;
	int				tmp_fd;
	unsigned int	tmp_max_distance;

	if ((tmp_fd = open(tmp_file, O_CREAT | O_WRONLY | O_TRUNC, 0600)) == -1)
		return (EXIT_FAILURE);
	while (*filenames != NULL)
	{
		tmp_max_distance = 0;
		filename = get_filename((*filenames)->content);
		dprintf(tmp_fd, "//Functions from file : %s\n", filename);
		if (get_prototypes_file((char *)(*filenames)->content, \
		tmp_fd, &tmp_max_distance))
		{
			ft_lstclear(filenames, free);
			close(tmp_fd);
			return (EXIT_FAILURE);
		}
		ft_lstdel_front(filenames, free);
		if (tmp_max_distance > *max_distance)
			*max_distance = tmp_max_distance;
	}
	return (EXIT_SUCCESS);
}

/*
int	main(int argc, char **argv)
{
	unsigned int	max_distance;

	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "Usage: ./print_code filepath\n");
		return (EXIT_FAILURE);
	}
	max_distance = 0;
	get_prototypes_file(argv[1], 1, &max_distance);
	ft_printf("The max distance for file %s is %u\n", argv[1], max_distance);
	return (EXIT_SUCCESS);
}
*/
