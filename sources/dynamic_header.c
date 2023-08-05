/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:00:35 by nsainton          #+#    #+#             */
/*   Updated: 2023/08/05 10:47:26 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

extern char **environ;

/*
	PATH_SIZE is defined as 1024 in header_int.h
	We allocate a large char array for the path in order to get sure
	that even for directories that are nested deep into the files tree
	the path won't overflow the path array
*/
static int	get_path(const char *name, char *path_array)
{
	if (*name == '/')
	{
		strcpy(path_array, name);
		return (0);
	}
	if (getcwd(path_array, PATH_SIZE) == NULL)
	{
		perror("Can't retrieve current working directory");
		return (1);
	}
	strcat(path_array, "/");
	strcat(path_array, name);
	return (0);
}
	
static int	write_script(const char *script_path)
{
	int		script_fd;
	int		err;

	if (! access(script_path, F_OK) && unlink(script_path) == -1)
	{
		fprintf(stderr, "Can't unlink : %s\n", script_path);
		return (1);
	}
	if ((script_fd = open(script_path, O_CREAT | O_WRONLY, 00700)) == -1)
	{
		fprintf(stderr, "Can't open file : %s\n", script_path);
		return (1);
	}
	err = (write(script_fd, HEADER_SCRIPT, strlen(HEADER_SCRIPT)) < 1);
	if (err)
		fputs("Can't write file : SCRIPT_NAME\n", stderr);
	close(script_fd);
	return (err);
}

static void	set_args(const char *args[3], const char *script_path, \
const char *header_path)
{
	*args = script_path;
	*(args + 1) = header_path;
	*(args + 2) = NULL;
}

int	dynamic_header(const char *header_name, \
const char *script_path)
{
	char		header_path[PATH_SIZE];
	const char	*args[3];
	int			status;
	int			pid;

	if (*environ == NULL)
	{
		fprintf(stderr, "No environment\n");
		return (1);
	}
	if (get_path(header_name, header_path) || write_script(script_path))
		return (1);
	pid = fork();
	if (pid < 0)
	{
		fprintf(stderr, "Couldn't fork process\n");
		return (1);
	}
	if (pid == 0)
	{
		set_args(args, script_path, header_path);
		execve(script_path, (char **)args, environ);
		fprintf(stderr, "Couldn't use execve\n");
		exit(1);
	}
	wait(&status);
	unlink(script_path);
	return (status);
}
