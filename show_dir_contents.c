/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_dir_contents.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:49:58 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/04 10:25:28 by nsainton         ###   ########.fr       */
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
			write(1, dir->d_name, strlen(dir->d_name));
			printf("Not a Directory : %s\n", dir->d_name);
		else if (! (strcmp(dir->d_name, ".") && strcmp(dir->d_name, "..")))
			continue ;
		else
		{
			printf("It is a directory : %s\n", dir->d_name);
			printf("These are its contents\n");
			printf("----------------------\n");
			sprintf(d_path, "%s/%s", path, dir->d_name);
			show_dir(d_path);
		}
	}
	closedir(d);
}

int	get_dir_entries(char *path, t_list **lst)
{
	DIR				*d;
	struct dirent	*dir;
	char			d_path[1000];
	t_list			*name;
	int				error;

	if (! (d = opendir(path)))
		return ;
	while ((dir = readdir(d)))
	{
		if (dir->d_type != DT_DIR)
		{
			if (! name = ft_lstnew_cpy(dir->d_name, strlen(dir->d_name) + 1))
				return (1);
			ft_lst_add_front(lst, name);
		}
		else if (! (strcmp(dir->d_name, ".") && strcmp(dir->d_name, "..")))
			continue ;
		else
		{
			sprintf(d_path, "%s/%s", path, dir->d_name);
			if (error = get_dir_entries(d_path, lst))
				return (error);
		}
	}
	closedir(d);
	return (0);
}

struct dirent
int	main(int ac, char **av)
{
	if (ac < 2)
		return (EXIT_FAILURE);
	show_dir(av[1]);
	return (EXIT_SUCCESS);
}
