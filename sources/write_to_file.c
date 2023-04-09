/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:09:05 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/04 16:11:28 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
static void	cut_prototype(char *prototype, t_cchar *str)
{
	size_t	coma_index;
	char	*next_coma;

	dprintf(STDERR_FILENO, "In function : %s\n", __func__);
	dprintf(STDERR_FILENO, "This is the original string : %s\n", str);
	coma_index = 0;
	while (tab_len(str + coma_index) > MAX_LINE_LEN)
	{
		next_coma = strchr(str, ',');
		while (next_coma && (next_coma - str) < MAX_LINE_LEN)
		{
			coma_index = (next_coma - prototype);
			next_coma = strchr(str + coma_index, ',');
		}
		strcat(prototype, str + coma_index);
		strcat(prototype, "\\\n");
		str += coma_index;
		coma_index = 0;
	}
}
*/

static int	build_prototype(char **prototype, t_string *str, ssize_t n_read)
{
	size_t	p_size;
	
	p_size = (size_t)n_read + 4 + 2 * tab_len(str->str) / MAX_LINE_LEN;
	if (! (*prototype = malloc(sizeof *str->str * p_size)))
		return (1);
	**prototype = 0;
	strcat(*prototype, str->str);
	/*
	if (tab_len(str->str) < MAX_LINE_LEN)
	{
		dprintf(STDERR_FILENO, "This is the string : %s\n", str->str);
		dprintf(STDERR_FILENO, "This is its len : %ld\n", tab_len(str->str));
		strcat(*prototype, str->str);
	}
	else
		cut_prototype(*prototype, str->str);
	*/
	return (0);
}

static ssize_t	write_function(t_string *str, ssize_t n_read, int dst)
{
	char	*prototype;
	char	*end;

	if (build_prototype(&prototype, str, n_read))
		return (-1);
	end = strrchr(prototype, ')');
	if (! end)
	{
		free(prototype);
		return (-1);
	}
	*(prototype + (end - prototype) + 1) = 0;
	strcat(prototype, ";\n\n");
	n_read = write(dst, prototype, strlen(prototype));
	free(prototype);
	return (n_read);
}

static int	write_functions(t_cchar *src_path, t_cint dst_fd, int *max)
{
	FILE		*src;
	t_string	line;
	ssize_t		n_read;
	int			distance;

	//dprintf(STDERR_FILENO, "In function : %s\n", __func__);
	if (! (src = fopen(src_path, "r")))
	{
		perror(src_path);
		return (1);
	}
	//dprintf(STDERR_FILENO, "The source has been opened : %s\n", src_path);
	line.str = NULL;
	line.size = 0;
	distance = 0;
	while ((n_read = getline_tstring(&line, src)) > 0)
	{
		//dprintf(STDERR_FILENO, "This is the line : %s", line.str);
		distance = is_func_prototype(line.str);
		*max = (distance > *max) * distance + (distance <= *max) * *max;
		if (distance && write_function(&line, n_read, dst_fd) < 1)
		{
			free(line.str);
			fclose(src);
			return (1);
		}
	}
	free(line.str);
	fclose(src);
	return (0);
}

int	write_to_file(t_cchar *src_path, t_cint fd)
{
	int			max_distance;

	max_distance = 0;
	if (write_functions(src_path, fd, &max_distance))
	{
		dprintf(STDERR_FILENO, "The function write_functions has returned an error on the file : %s\n", src_path);
		return (0);
	}
	return (max_distance);
}
