/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_prototypes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:41:48 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/30 16:51:04 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static unsigned int	next_coma(t_cchar *line, const unsigned int max)
{
	char			*coma;
	unsigned int	next_coma;

	//printf("Line : %s\n", line);
	coma = strchr(line, ',');
	next_coma = 0;
	while (coma && tabsnlen(line, coma - line) < max)
	{
		next_coma = coma - line;
		coma = strchr(line + next_coma + 1, ',');
	}
	return (next_coma);
}

static void	slice_line(char *line, const unsigned int max, \
unsigned int lines_count)
{
	unsigned int	start;
	unsigned int	slice_index;

	start = 0;
	while (lines_count > 1)
	{
		slice_index = next_coma(line, max) + 1;
		memmove(line + start + slice_index + 3, line + start + slice_index + 1, \
		strlen(line + start + slice_index + 1) + 1);
		*(line + slice_index + 1) = '\\';
		*(line + slice_index + 2) = '\n';
		start = slice_index + 3;
		lines_count --;
	}
}

static int	write_prototype(char *line, int ofd, size_t length, \
const unsigned int max_distance)
{
	char			*prototype;
	char			*tmp;
	unsigned int	proto_len;
	unsigned int	lines_count;
	int				err;

	tmp = NULL;
	if (*line == '/' || *line == '\n')
		return ((write(ofd, line, length) == -1));
	prototype = format_prototype(line, max_distance, &proto_len);
	if (! prototype)
	{
		dprintf(STDERR_FILENO, "Couldn't built prototype\n");
		return (1);
	}
	lines_count = tabslen(prototype) / MAX_LINE_LEN + 1;
	if (lines_count > 1 && \
	! (tmp = realloc(prototype, proto_len + 2 * (lines_count - 1) + 1)))
	{
		dprintf(STDERR_FILENO, "Reallocation error\n");
		return (1);
	}
	if (lines_count > 1)
	{
		prototype = tmp;
		slice_line(prototype, MAX_LINE_LEN, lines_count);
	}
	err = (write(ofd, prototype, proto_len + 2 * (lines_count - 1)) < 1);
	free(prototype);
	return (err);
}

int	write_prototypes(const char *source_file, const char *destination_file, const unsigned int max_distance)
{
	FILE	*istream;
	int		ofd;
	char	*line;
	size_t	linesize;
	ssize_t	nread;

	istream = fopen(source_file, "r");
	if (! istream)
		return (1);
	/*
	ofd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC);
	if (ofd == -1)
	{
		fclose(istream);
		return (-1);
	}
	*/
	(void)destination_file;
	ofd = 1;
	line = NULL;
	linesize = 0;
	while ((nread = getline(&line, &linesize, istream)) > 0)
	{
		if (write_prototype(line, ofd, (unsigned int)nread, max_distance))
			break ;
	}
	free(line);
	if (! feof(istream))
	{
		dprintf(STDERR_FILENO, "Error while writting prototypes\n");
		fclose(istream);
		return (1);
	}
	fclose(istream);
	return (0);
}
