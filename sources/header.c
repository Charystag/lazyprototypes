/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:53:03 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/12 19:39:18 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	arguments_error(t_cint fd)
{
		ft_dprintf(fd, "Please provide the path to the folder to \
search as the first argument\n");
		ft_dprintf(fd, "Please provide the path to the file  you want \
to create as the last argument\n");
		ft_dprintf(fd, "ex : path_to_executable path_to_project/sources \
path_to_project/includes/functions.h\n");
		return (EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_descriptors	desc;
	int				max[2];
	int				error;
	t_list			*entries;
	char			*filename;

	if (ac < 3)
		return (arguments_error(STDERR_FILENO));
	//index = 0;
	remove(TMP_FILE);
	desc.tmp = open(TMP_FILE, O_CREAT | O_WRONLY, 0644);
	if (desc.tmp < 0)
		return (EXIT_FAILURE);
	entries = NULL;
	if (get_dir_entries(av[1], &entries, EXT))
	{
		ft_lstclear(&entries, free);
		return (EXIT_FAILURE);
	}
	*max = 0;
	while (entries)
	{
		filename = ft_strrchr((char *)entries->content, '/');
		filename = filename + (filename != NULL);
		if (! filename)
			filename = (char *)entries->content;
		//print_color_string(entries->content, GRN, STDERR_FILENO);
		dprintf(desc.tmp, "//Functions from file : %s\n", filename);
		*(max + 1) = write_to_file((char *)entries->content, desc.tmp);
		if (*(max + 1) > *max)
			*max = *(max + 1);
		ft_lstdel_front(&entries, free);
	}
	close(desc.tmp);
	error = create_destination(av[2], TMP_FILE, *max);
	//remove(TMP_FILE);
	return ((error > 0) * EXIT_FAILURE);
}
