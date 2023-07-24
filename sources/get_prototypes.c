/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prototypes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:48:42 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/24 12:18:38 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//int	parsefile(char *buufer, size_t size, FILE *fstream, 
int	get_prototypes_file(const char *filename, int tmp_fd, int *max_distance)
{
	char	*buffer;
	size_t	size;
	FILE	*filestream;
	ssize_t	nread;
	int		swit;

	size = LINE_MAX_SIZE;
	if ((buffer = malloc(size * sizeof * buffer)) == NULL)
	{
		dprintf(STDERR_FILENO, "Couldn't allocate buffer of size : %zd\n", \
		size);
		return (EXIT_FAILURE);
	if ((filestream = fopen(filename, "r")) == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Couldn't open file : %s\n", filename);
		return (EXIT_FAILURE);
	}
	/*
	while ((nread = getline(&buffer, &size, filestream)) > 0)
	{
		swit = comment_switch(buffer, &swit, (size_t)nread);
		if (! isprototype(buffer) || swit)
			continue ;
	*/
	return (EXIT_SUCCESS);
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
		filename = getname((*filenames)->content);
		dprintf(tmp_fd, "//Functions from file : %s\n", filename);
		get_prototypes_file(tmp_fd, (char *)(*filenames)->content, \
		&tmp_max_distance)
		ft_lstdel_front(filenames, free);
		if (tmp_max_distance > *max_distance)
			*max_distance = tmp_max_distance;
	}
	return (EXIT_SUCCESS);
}
