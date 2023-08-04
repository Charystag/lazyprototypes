/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:00:35 by nsainton          #+#    #+#             */
/*   Updated: 2023/08/04 17:21:16 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
# define SCRIPT_NAME "42dynamicheaderscript.sh"

static int	write_script(void)
{
	int	script_fd;
	int	err;

	if ((script_fd = open(SCRIPT_NAME, O_CREAT | O_WRONLY, 00700)) == -1)
	{
		fputs("Can't open file : SCRIPT_NAME\n", stderr);
		return (1);
	}
	err = (write(script_fd, HEADER_SCRIPT, strlen(HEADER_SCRIPT)) < 1);
	if (err)
		fputs("Can't write file : SCRIPT_NAME\n", stderr);
	close(script_fd);
	return (err);
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	if (! access(SCRIPT_NAME, F_OK) && remove(SCRIPT_NAME) == -1)
	{
		fputs("Couldn't remove file : SCRIPT_NAME\n", stderr);
		return (1);
	}
	if (write_script())
		return (1);
	return (0);
}
