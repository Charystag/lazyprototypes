/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:06:43 by nsainton          #+#    #+#             */
/*   Updated: 2023/08/04 15:57:49 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static unsigned int	right_format(const char *line)
{
	char			*main;
	char			*st;
	char			*par;
	char			*closing;
	unsigned int	whitespace_index;

	if (! isalpha(*line) && *line != '_')
		return (0);
	if (! ((par = strchr(line, '(')) && (closing = strchr(line, ')'))))
		return (0);
	if ((st = strstr(line, "static")) && st < par)
		return (0);
	main = strchr(line, 'm');
	if (main && main < par && ! strncmp(main, "main", strlen("main")))
		return (0);
	whitespace_index = 0;
	while (par != line && ! whitespace_index)
	{
		if (space_or_tab(*par) && ! space_or_tab(*(par - 1)))
			whitespace_index = (par - line);
		par --;
	}
	return (whitespace_index);
}

int	open_parenthesis(const char *function)
{
	int	parenthesis;

	parenthesis = 0;
	while (*function)
	{
		parenthesis += (*function == '(') - (*function == ')');
		function ++;
	}
	return (parenthesis);
}

unsigned int	compute_distance(const char *line, \
const unsigned int end_of_types)
{	
	unsigned int	i;
	unsigned int	distance;
	int				inspace;

	i = 0;
	distance = 0;
	while (i < end_of_types)
	{
		if (! space_or_tab(*(line + i)))
		{
			distance ++;
			inspace = 0;
		}
		else if (! inspace)
		{
			distance ++;
			inspace = 1;
		}
		i ++;
	}
	return (distance);
}

unsigned int	is_func_prototype(const char *line)
{
	unsigned int	whitespace;

	if (! (whitespace = right_format(line)))
		return (0);
	return (compute_distance(line, whitespace));
}
