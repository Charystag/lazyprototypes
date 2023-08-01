/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir_entries.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:50:11 by nsainton          #+#    #+#             */
/*   Updated: 2023/08/01 07:50:13 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

/*
	We know that NAME_MAX is defined to be 254, so having a buffer of 1024
	for the path seems to ensure that this buffer won't overflow. However,
	this choice is unsafe and has to be fixed in another update
*/

static int	wrong_extension(const char *filename, const char *ext)
{
	const char	*dot;

	dot = ft_strrchr(filename, '.');
	if (! dot)
		return (1);
	return (ft_strcmp(dot, ext));
}

int	get_dir_entries(char *path, struct s_list **lst, const char *ext)
{
	DIR				*d;
	struct dirent	*dir;
	char			d_path[1024];
	struct s_list	*name;
	int				error;

	if (! (d = opendir(path)))
		return (1);
	while ((dir = readdir(d)))
	{
		sprintf(d_path, "%s/%s", path, dir->d_name);
		if (dir->d_type != DT_DIR)
		{
			if (wrong_extension(dir->d_name, ext))
				continue ;
			if (! (name = ft_lstnew_cpy(d_path, strlen(d_path) + 1)))
				return (1);
			ft_lstadd_front(lst, name);
		}
		else if (! (strcmp(dir->d_name, ".") && strcmp(dir->d_name, "..")))
			continue ;
		else
		{
			if ((error = get_dir_entries(d_path, lst, ext)))
				return (error);
		}
	}
	closedir(d);
	return (0);
}
