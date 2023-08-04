/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir_entries.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:50:11 by nsainton          #+#    #+#             */
/*   Updated: 2023/08/04 16:34:23 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*
	We know that NAME_MAX is defined to be 254, so having a buffer of 1024
	for the path seems to ensure that this buffer won't overflow. However,
	this choice is unsafe and has to be fixed in another update
*/

static int	wrong_extension(const char *filename, const char *ext)
{
	const char	*dot;

	dot = strrchr(filename, '.');
	if (! dot)
		return (1);
	return (strcmp(dot, ext));
}

int	get_dir_entries(const char *path, struct s_list **lst, const char *ext)
{
	DIR				*d;
	struct dirent	*dir;
	char			d_path[1024];
	struct s_list	*name;
	int				error;

	if (! (d = opendir(path)))
		return (1);
	error = 0;
	while ((dir = readdir(d)))
	{
		sprintf(d_path, "%s/%s", path, dir->d_name);
		if (dir->d_type != DT_DIR)
		{
			if (wrong_extension(dir->d_name, ext))
				continue ;
			if (! (name = ft_lstnew_cpy(d_path, strlen(d_path) + 1)))
			{
				error = 1;
				break ;
			}
			ft_lstadd_front(lst, name);
		}
		else if (! (strcmp(dir->d_name, ".") && strcmp(dir->d_name, "..")))
			continue ;
		else
		{
			if ((error = get_dir_entries(d_path, lst, ext)))
				break ;
		}
	}
	closedir(d);
	return (error);
}
