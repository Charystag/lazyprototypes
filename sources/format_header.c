/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:02:38 by nsainton          #+#    #+#             */
/*   Updated: 2023/08/04 16:29:14 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

static int	stop_creation(const char *destination_path)
{
	int		new;
	int		remov;

	remov = 'y';
	new = access(destination_path, F_OK);
	if (! new)
	{
		printf("The file : %s already exists, if you wish to remove it and \
pursue : type \'y\', otherwise enter any other character\n"\
		, destination_path);
		remov = tolower(getchar());
	}
	if (remov != 'y')
		return (1);
	if (! new)
		remove(destination_path);
	return (0);
}

static int	protect(unsigned int index, int c)
{
	(void)index;
	if (c != '.')
		return (toupper(c));
	return ('_');
}

static int	write_concat(int header_fd, const char *s1, const char *s2, \
const char *sep)
{
	char	buf[1024];
	size_t	len;

	*buf = 0;
	len = ft_strcat(buf, s1);
	if (sep)
		len += ft_strcat(buf + len, sep);
	len += ft_strcat(buf + len, s2);
	if (sep)
		len += ft_strcat(buf + len, sep);
	len += ft_strcat(buf + len, "\n");
	return ((write(header_fd, buf, len) < 1));
}

static int	include_headers(int header_fd, const char *header, \
char **includes)
{
	char	*header_prot;
	int		err;

	if ((header_prot = \
	ft_strmapi(get_filename((char *)header), protect)) == NULL)
		return (1);
	err = 0;
	if (write(header_fd, HEADER, strlen(HEADER)) < 1)
		err = 1;
	if (err || write_concat(header_fd, IND, header_prot, NULL))
		err = 1;
	if (err || write_concat(header_fd, D, header_prot, NULL))
		err = 1;
	while (! err && *includes != NULL)
	{
		if (write_concat(header_fd, INC, *includes, "\""))
			err = 1;
		includes ++;
	}
	free(header_prot);
	return (err);
}

int	header_header(const char *header, char **includes)
{
	int	header_fd;

	if (stop_creation(header))
		return (-1);
	header_fd = open(header, O_CREAT | O_WRONLY | O_TRUNC, 00644);
	if (header_fd < 0)
		return (-1);
	if (include_headers(header_fd, header, includes))
	{
		close(header_fd);
		return (-1);
	}
	return (header_fd);
}
