/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_dir_contents.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:49:58 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/31 22:23:07 by nsainton         ###   ########.fr       */
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
void	show_dir(char *path)
{
	DIR				*d;
	struct dirent	*dir;
	char			d_path[1024];

	d = NULL;
	if (! (d = opendir(path)))
		return ;
	while ((dir = readdir(d)))
	{
		write(1, "\n", 1);
		if (dir->d_type != DT_DIR)
			ft_printf("Not a Directory : %s\n", dir->d_name);
		else if (! (strcmp(dir->d_name, ".") && strcmp(dir->d_name, "..")))
			continue ;
		else
		{
			ft_printf("It is a directory : %s\n", dir->d_name);
			ft_printf("These are its contents\n");
			ft_printf("----------------------\n");
			sprintf(d_path, "%s/%s", path, dir->d_name);
			show_dir(d_path);
		}
	}
	closedir(d);
}

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
