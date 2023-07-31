/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:53:03 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/31 15:29:49 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static _Noreturn void usage(int status)
{
	char	*program_name;

	program_name = PROG_NAME;
	printf ("\
Usage: %s SRCS_FOLDER DESTINATION_FILE [FILES_TO_INCLUDE]\n", program_name);
	fputs("With no FILES_TO_INCLUDE files will have to be manually included\n", \
	stdout);
	printf("\
Examples :\n\
  	%s sources includes/prototypes.h include1.h include2.h\n\
	%s sources includes/prototypes.h\n\
", program_name, program_name);
	exit(status);
}

int	main(int argc, char **argv)
{
	unsigned int	max_distance;
	t_list			*entries;
	int				err;

	if (argc <= 2)
		usage(1);
	max_distance = 0;
	entries = NULL;
	if (get_dir_entries(argv[1], &entries, EXT))
	{
		ft_dprintf(STDERR_FILENO, \
		"Error while getting entries from directory : %s\n", argv[1]);
		return (1);
	}
	err = 0;
	if(err || get_prototypes(&entries, TMP_FILE, &max_distance))
		err = 1;
	if (err || write_prototypes(TMP_FILE, argv[2], max_distance, argv + 3))
		err = 1;
	if (remove(TMP_FILE))
	{
		ft_dprintf(STDERR_FILENO, "Couldn't remove temporary file\n");
		err = 1;
	}
	return (err);
}
