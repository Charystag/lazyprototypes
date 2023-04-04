/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_dir_contents.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:49:58 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/04 16:12:04 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

typedef const char	t_cchar;

void	show_dir(char *path)
{
	DIR				*d;
	struct dirent	*dir;
	char			d_path[1000];

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

/*
static void	print_node(void *node)
{
	ft_printf("%s\n", (char *)node);
}
*/

static int	wrong_extension(t_cchar *filename, t_cchar *ext)
{
	t_cchar	*dot;

	//ft_printf("Name : %s\n", filename);
	dot = ft_strrchr(filename, '.');
	if (! dot)
		return (1);
	return (ft_strcmp(dot, ext));
}

int	get_dir_entries(char *path, t_list **lst, char *ext)
{
	DIR				*d;
	struct dirent	*dir;
	char			d_path[300];
	t_list			*name;
	int				error;

	if (! (d = opendir(path)))
		return (1);
	while ((dir = readdir(d)))
	{
		sprintf(d_path, "%s/%s", path, dir->d_name);
		if (wrong_extension(dir->d_name, ext))
			continue ;
		if (dir->d_type != DT_DIR)
		{
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
