/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:53:03 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/31 19:25:36 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
//Use dirent.h header to list the file in the provided directory

int	main(int ac, char **av)
{
	t_descriptors	desc;
	//int		index;
	char	*file;
	char	*cpy;
	int		max[2];
	int		error;

	if (ac < 3)
	{
		dprintf(STDERR_FILENO, "Please provide the path to the folder to search as the first argument\n");
		dprintf(STDERR_FILENO, "Please provide the path to the file  you want to create as the last argument\n");
		dprintf(STDERR_FILENO, "ex : path_to_executable path_to_project/sources path_to_project/includes/functions.h\n");
		return (EXIT_FAILURE);
	}
	if (getlist(&desc.src, av[1], &file, &cpy))
		return (EXIT_FAILURE);
	//index = 0;
	remove(TMP_FILE);
	desc.tmp = open(TMP_FILE, O_CREAT | O_WRONLY, 0644);
	if (desc.tmp < 0)
	{
		fclose(desc.src);
		free(file);
		free(cpy);
		return (EXIT_FAILURE);
	}
	*max = 0;
	while (desc.tmp > 0 && fgets(file, FILE_NAME_SIZE + 1, desc.src))
	{
		//printf("This is the string #%.2d returned by the command: %s", index, file);
		*cpy = 0;
		strncat(cpy, file, strlen(file) - 1);
		dprintf(desc.tmp, "//Functions from file : %s\n", file + strlen(av[1]) + (*(file + strlen(av[1])) == '/'));
		//printf("This is the max distance from file[%d] : %d\n", index ++, (*(max + 1) = write_to_file(cpy, desc.tmp)));
		*(max + 1) = write_to_file(cpy, desc.tmp);
		if (*(max + 1) > *max)
			*max = *(max + 1);
	}
	pclose(desc.src);
	close(desc.tmp);
	free(file);
	free(cpy);
	error = create_destination(av[2], TMP_FILE, *max);
	remove(TMP_FILE);
	return ((error > 0) * EXIT_FAILURE);
}
