/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:02:08 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/31 13:07:41 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	is_path_char(int c)
{
	return (isalnum(c) || c == '.' || c == '/' || c == '_' || c == '-');
}

int	valid_path(t_cchar *path)
{
	while (*path)
	{
		if (! is_path_char(*path))
		{
			dprintf(STDERR_FILENO, "This is the problematic char : %c\n", *path);
			return (0);
		}
		path ++;
	}
	return (1);
}

int	space_or_tab(int c)
{
	return (c == ' ' || c == '\t');
}

size_t	tab_len(t_cchar *line)
{
	size_t	tabs;
	size_t	len;

	tabs = 0;
	len = 0;
	while (*(line + len))
	{
		tabs += (*(line + len) == '\t');
		len ++;
	}
	return (len + 3 * tabs);
}
