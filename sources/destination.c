/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:01:27 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/12 19:26:00 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <sys/errno.h>

static int	stop_creation(t_cchar *destination_path)
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

static int	build_line(char *new_line, t_cchar *line, int max)
{
	int		index;

	index = 0;
	*new_line = 0;
	//dprintf(STDERR_FILENO, "This is the maximum : %d\n", max);
	//dprintf(STDERR_FILENO, "This is the line : %s", line);
	while (isalpha(*(line + index)) || *(line + index) == '_')
		index ++;
	//dprintf(STDERR_FILENO, "This is the index : %d\n", index);
	strncat(new_line, line, index);
	max = (max - index) / 4 + (((max - index) % 4) > 0);
	//dprintf(STDERR_FILENO, "This is the new maximum : %d\n\n", max);
	if (max > 10)
		return (1);
	//dprintf(STDERR_FILENO, "This is the line : %sThis is the max : %d\n", line, max);
	while (max-- > 0)
		strcat(new_line, "\t");
	while (! isalpha(*(line + index)) && *(line + index) != '*')
		index ++;
	if (tab_len(new_line) + strlen(line + index) > MAX_LINE_LEN)
		cat_line_ret(new_line, line + index, MAX_LINE_LEN - tab_len(new_line));
	else
		strcat(new_line, line + index);
	//dprintf(STDERR_FILENO, "This is the new line : %s\n", new_line);
	return (0);
}

static int	write_line(t_cchar *line, t_cint fd, t_cint max)
{
	char	*new_line;
	int		error;

	if (! isalpha(*line))
		return ((write(fd, line, strlen(line)) < 1));
	new_line = malloc (sizeof * new_line * (strlen(line) + 33));
	if (! new_line)
		return (1);
	if (build_line(new_line, line, max))
	{
		free(new_line);
		return (1);
	}
	error = (write(fd, new_line, strlen(new_line)) < 1);
	free(new_line);
	return (error);
}

static int format_destination(t_cint dst, FILE *tmp, t_cint max)
{
	t_string	str;
	int			error;

	bzero(&str, sizeof str);
	error = 0;
	while (getline_tstring(&str, tmp) > 0)
	{
		error = write_line(str.str, dst, max);
		/*
		dprintf(STDERR_FILENO, "This is the return of write_line : %d\n", error);
		dprintf(STDERR_FILENO, "This is the original line : %s\n", str.str);
		*/
		if (error)
		{
			dprintf(DEBUG_OUT, "Bonjour\n");
			break ;
		}
	}
	free(str.str);
	return (error);
}

int	create_destination(t_cchar *destination_path, t_cchar *tmp_path, t_cint max)
{
	int			dst;
	FILE		*tmp;
	int			error;
	char		*name;

	if (stop_creation(destination_path))
	{
		dprintf(DEBUG_OUT, "Creation Stopped\n");
		return (1);
	}
	tmp = fopen(tmp_path, "r");
	if (! tmp)
	{
		dprintf(DEBUG_OUT, "Couldn't open temporary file\n");
		return (1);
	}
	dst = open(destination_path, O_CREAT | O_WRONLY, 0644);
	if (dst < 0)
	{
		dprintf(DEBUG_OUT, "Couldn't open destination file\n");
		fclose(tmp);
		return (1);
	}
	//dprintf(STDERR_FILENO, "This is the max distance from all the previous file : %d\n", max);
	write(dst, HEADER, strlen(HEADER));
	name = strrchr(destination_path, '/');
	name += (name != NULL);
	/*
	dprintf(STDERR_FILENO, "%s\n", destination_path);
	dprintf(STDERR_FILENO, "D_PATH PRINTED\n");
	*/
	error = 0;
	if (! name)
	{
		//dprintf(STDERR_FILENO, "No / encountered\n");
		name = (char *)destination_path;
	}
	//dprintf(STDERR_FILENO, "%s\n", name);
	error = (write_header_prot(dst, name) || format_destination(dst, tmp, max));
	//dprintf(STDERR_FILENO, "This is the return from function format_destination : %d\n", error);
	if (! error)
		write(dst, END, strlen(END));
	else
		dprintf(DEBUG_OUT, "Error while writing to file\n");
	fclose(tmp);
	close(dst);
	return (error);
}
