/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:06:43 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/19 19:53:15 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	right_format(t_cchar *line)
{
	char	*main;
	char	*st;
	char	*par;

	if (! isalpha(*line))
		return (0);
	if (! (par = strchr(line, '(')))
		return (0);
	if ((st = strstr(line, "static")) && st < par)
		return (0);
	main = strchr(line, 'm');
	if (main && ! strncmp(main, "main", strlen("main")))
		return (0);
	return (1);
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

int	is_func_prototype(t_cchar *line)
{
	int	i;
	int	space;
	int	distance;

	if (! right_format(line))
		return (0);
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
}
