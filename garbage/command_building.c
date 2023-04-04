/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_building.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:08:26 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/31 09:41:34 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	build_command(char **command, t_cchar *dirname)
{
	size_t	len;
	char	*com;

	if (! valid_path(dirname))
	{
		dprintf(STDERR_FILENO, "The path to the directory is not valid\n");
		return (COMMAND);
	}
	len = strlen(UTILITY) + strlen(OPT) + strlen(dirname);
	*command = malloc((len + 1) * sizeof **command);
	if (! *command)
		return (MEMORY);
	com = *command;
	*com = 0;
	strcat(com, UTILITY);
	strcat(com, dirname);
	strcat(com, OPT);
	return (0);
}

int	getlist(FILE **list, t_cchar *path, char **filename, char **cpy)
{
	char	*command;
	int		error;

	if ((error = build_command(&command, path)))
		return (error);
	if (! (*filename = malloc(FILE_NAME_SIZE + 1)))
	{
		free(command);
		return (MEMORY);
	}
	if (! (*cpy = malloc(FILE_NAME_SIZE)))
	{
		free(command);
		free(*filename);
		return (MEMORY);
	}
	if (! (*list = popen(command, "r")))
	{
		free(command);
		free(*filename);
		free(*cpy);
		return (MEMORY);
	}
	free(command);
	return (0);
}
