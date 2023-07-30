/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_prototypes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:41:48 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/30 17:54:52 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static unsigned int	find_next_sep(t_cchar *line, const unsigned int max, \
const int separator)
{
	char			*sep;
	unsigned int	next_sep;

	sep = strchr(line, separator);
	next_sep = 0;
	while (sep && tabsnlen(line, sep - line) < max)
	{
		next_sep = sep - line;
		sep = strchr(line + next_sep + 1, separator);
	}
	return (next_sep);
}

static unsigned int	next_sep(t_cchar *line, const unsigned int max)
{
	unsigned int	cutting_point;

	cutting_point = find_next_sep(line, max, ',');
	if (! cutting_point && tabslen(line + cutting_point) >= max)
		cutting_point = find_next_sep(line, max, ' ');
	if (! cutting_point && tabslen(line + cutting_point) >= max)
		cutting_point = find_next_sep(line, max, '\t');
	return (cutting_point);
}

static void	slice_line(char *line, const unsigned int max)
{
	unsigned int	start;
	unsigned int	slice_index;

	start = 0;
	while (strlen(line + start) > max)
	{
		slice_index = next_sep(line + start, max) + 1;
		memmove(line + start + slice_index + 3, line + start + slice_index + 1, \
		strlen(line + start + slice_index + 1) + 1);
		*(line + start + slice_index + 1) = '\\';
		*(line + start + slice_index + 2) = '\n';
		start += slice_index + 3;
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
	! (tmp = realloc(prototype, proto_len + 4 * (lines_count - 1) + 1)))
	{
		dprintf(STDERR_FILENO, "Reallocation error\n");
		return (1);
	}
	if (lines_count > 1)
	{
		prototype = tmp;
		slice_line(prototype, MAX_LINE_LEN);
	}
	err = (write(ofd, prototype, strlen(prototype)) < 1);
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
