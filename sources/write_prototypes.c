/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_prototypes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:41:48 by nsainton          #+#    #+#             */
/*   Updated: 2023/08/04 15:57:04 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static unsigned int	find_next_sep(const char *line, const unsigned int max, \
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

/*
	If line is as such : `const char * const bash_license = N_("License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>\n");`
	like encountered in bash source files, it will be splitted from
	the beginning of the line at each time (as index will be 0 if
	we do not look for space). This is why if we can't find no ','
	or '\t' to split on and our line is still too long, we need to
	split over space to ensure that our line won't be too splitted
	and thus overflowing our buffer.
*/
static unsigned int	next_sep(const char *line, const unsigned int max)
{
	unsigned int	cutting_point;

	cutting_point = find_next_sep(line, max, ',');
	if (! cutting_point && tabslen(line + cutting_point) >= max)
		cutting_point = find_next_sep(line, max, '\t');
	if (! cutting_point && tabslen(line + cutting_point) >= max)
		cutting_point = find_next_sep(line, max, ' ');
	return (cutting_point);
}

static void	slice_line(char *line, const unsigned int max)
{
	unsigned int	start;
	unsigned int	slice_index;

	start = 0;
	while (tabslen(line + start) > max)
	{
		slice_index = next_sep(line + start, max);
		slice_index += (*(line + start + slice_index) == ',');
		memmove(line + start + slice_index + 3, line + start + slice_index + 1, \
		strlen(line + start + slice_index + 1) + 1);
		*(line + start + slice_index + 1) = '\\';
		*(line + start + slice_index + 2) = '\n';
		start += slice_index + 3;
	}
}

/*
	We are supposed to allocate room for "\\\n" but we allocate slots
	for 2 extra lines in case we miscalculated a bit the needed number
	of lines.
	Such miscalculation could occur due to the way we compute the length
	vs the way we actually split the lines.
*/
static int	write_prototype(const char *line, int ofd, size_t length, \
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
	err = 0;
	lines_count = tabslen(prototype) / MAX_LINE_LEN + 1;
	if (lines_count > 1 && \
	! (tmp = realloc(prototype, proto_len + 4 * (lines_count - 1) + 1)))
	{
		dprintf(STDERR_FILENO, "Reallocation error\n");
		err = 1;
	}
	if (lines_count > 1 && ! err)
	{
		prototype = tmp;
		slice_line(prototype, MAX_LINE_LEN);
	}
	err = (err || (write(ofd, prototype, strlen(prototype)) < 1));
	free(prototype);
	return (err);
}

int	write_prototypes(const char *source_file, \
const char *destination_file, const unsigned int max_distance, \
char **includes)
{
	FILE	*istream;
	int		ofd;
	char	*line;
	size_t	linesize;
	ssize_t	nread;

	istream = fopen(source_file, "r");
	if (! istream)
		return (1);
	ofd = header_header(destination_file, includes);
	if (ofd == -1)
	{
		fclose(istream);
		return (1);
	}
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
	write(ofd, END, strlen(END));
	close(ofd);
	return (0);
}
