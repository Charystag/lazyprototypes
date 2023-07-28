/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:06:43 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/28 16:10:44 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static unsigned int	right_format(t_cchar *line)
{
	char			*main;
	char			*st;
	char			*par;
	unsigned int	whitespace_index;

	if (! isalpha(*line) && *line != '_')
		return (0);
	if (! (par = strchr(line, '(')))
		return (0);
	if ((st = strstr(line, "static")) && st < par)
		return (0);
	main = strchr(line, 'm');
	if (main && main < par && ! strncmp(main, "main", strlen("main")))
		return (0);
	whitespace_index = 0;
	while (par != line && ! whitespace_index)
	{
		if (isspace(*par) && ! isspace(*(par - 1)))
			whitespace_index = (par - line);
		par --;
	}
	return (whitespace_index);
}

int	open_parenthesis(t_cchar *function)
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

static unsigned int	compute_distance(t_cchar *line, \
const unsigned int end_of_types)
{	
	unsigned int	i;
	unsigned int	distance;
	int				inspace;

	i = 0;
	distance = 0;
	while (i < end_of_types)
	{
		if (! isspace(*(line + i)))
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

unsigned int	is_func_prototype(t_cchar *line)
{
	unsigned int	whitespace;

	if (! (whitespace = right_format(line)))
		return (0);
	return(compute_distance(line, whitespace));
	/*
	i = 0;
	space = 0;
	while (*(line + i) && *(line + i) != '\t')
		i ++;
	distance = i;
	while (*(line + i) && space_or_tab(*(line + i)))
	{
		space = 1;
		distance += (*(line + i) == ' ') + 4 * (*(line + i) == '\t');
		i ++;
	}
	//printf("Line : %s\nDistance : %d\n", line, distance * space);
	return (distance * space);
	*/
}
