/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prototypes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:48:42 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/31 17:31:39 by nsainton         ###   ########.fr       */
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

static int	initialize(struct s_str **buf, FILE **fstream, \
const char *filename)
{
	if ((*buf = calloc(1, sizeof **buf)) == NULL)
	{
		dprintf(STDERR_FILENO, "Couldn't allocate struct s_str of size : 1\n");
		return (1);
	}
	if ((*fstream = fopen(filename, "r")) == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Couldn't open file : %s\n", filename);
		tstr_del(*buf);
		return (1);
	}
	return (0);
}

int	get_prototypes_file(const char *filename, int tmp_fd, unsigned int *max_distance)
{
	FILE			*fstream;
	int				swit;
	struct s_str	*buf;
	int				eof;

	if (initialize(&buf, &fstream, filename))
		return (1);
	swit = 0;
	while (! get_codeline(&buf, fstream))
	{
		if (write_prototype(buf, &swit, tmp_fd, max_distance))
			break ;
	}
	if (! (eof = feof(fstream)))
		ft_dprintf(STDERR_FILENO, "Error while dealing with file : %s\n", filename);
	fclose(fstream);
	tstr_del(buf);
	return ((eof == 0));
}

char	*get_filename(char *content)
{
	char	*filename;

	filename = ft_strrchr((char *)content, '/');
	if (! filename)
		return (content);
	return (filename + 1);
}

unsigned int	get_prototypes(t_list **filenames, const char *tmp_file, unsigned int *max_distance)
{
	char			*filename;
	int				tmp_fd;
	unsigned int	tmp_max_distance;
	int				err;

	if ((tmp_fd = open(tmp_file, O_CREAT | O_WRONLY | O_TRUNC, 0600)) == -1)
		return (EXIT_FAILURE);
	while (*filenames != NULL)
	{
		tmp_max_distance = 0;
		filename = get_filename((char *)(*filenames)->content);
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
	if ((err = close(tmp_fd)) == -1)
		dprintf(STDERR_FILENO, "Error while closing file : %s\n", TMP_FILE);
	return (err);
}
