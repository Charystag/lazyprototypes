/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prototypes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:48:42 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/28 11:49:25 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_prototypes_file(const char *filename, int tmp_fd, int *max_distance)
{
	FILE			*fstream;
	int				swit;
	struct s_str	*buf;
	unsigned int	i;

	if ((buf = calloc(1, sizeof * buf)) == NULL)
	{
		dprintf(STDERR_FILENO, \
		"Couldn't allocate struct s_str of size : 1\n");
		return (EXIT_FAILURE);
	}
	if ((fstream = fopen(filename, "r")) == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Couldn't open file : %s\n", filename);
		return (EXIT_FAILURE);
	}
	(void)max_distance;
	i = 0;
	while (! get_codeline(&buf, fstream))
	{
		if (comment_switch(buf->str, &swit, buf->len) || \
		! is_func_prototype(buf->str))
			continue ;
		if (write(tmp_fd, buf->str, buf->len) < 0)
			break ;
		/*
		i ++;
		ft_printf("Line : %u\n", i);
		write(STDOUT_FILENO, buf->str, buf->len);
		*/
	}
	fclose(fstream);
	if (! feof(fstream))
		ft_dprintf(STDERR_FILENO, \
		"Error while dealing with file : %s\n", filename);
	tstr_delete(buf);
	/*
	while ((nread = getline(&buffer, &size, fstream)) > 0)
	{
		swit = comment_switch(buffer, &swit, (size_t)nread);
		if (! isprototype(buffer) || swit)
			continue ;
	*/
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

int	get_prototypes(t_list **filenames, const char *tmp_file, int *max_distance)
{
	char	*filename;
	int		tmp_fd;
	int		tmp_max_distance;

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
	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "Usage: ./print_code filepath\n");
		return (EXIT_FAILURE);
	}
	get_prototypes_file(argv[1], 0, NULL);
	return (EXIT_SUCCESS);
}
*/
