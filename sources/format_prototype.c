/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_prototype.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 10:50:03 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/30 16:28:58 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static unsigned int	proto_length(const char *prototype, \
const unsigned int max_distance, unsigned int *end_of_types, \
unsigned int *tabs_number)
{
	char			*parenthesis;
	char			*func_name;
	unsigned int	distance;

	parenthesis = strchr(prototype, '(');
	if (! parenthesis)
		return (0);
	while (parenthesis != prototype)
	{
		if (! isspace(*parenthesis) && isspace(*(parenthesis - 1)))
			break ;
		parenthesis--;
	}
	func_name = parenthesis;
	while (parenthesis != prototype)
	{
		if (isspace(*parenthesis) && !isspace(*(parenthesis - 1)))
			break ;
		parenthesis--;
	}
	*end_of_types = parenthesis - prototype;
	distance = compute_distance(prototype, *end_of_types);
	*tabs_number = (max_distance / TABLEN - distance / TABLEN + 1);
	return (distance + *tabs_number + compute_distance(func_name, strlen(func_name)));
}

static unsigned int	add_formated_string(char *to_format, \
const char *base_string, unsigned int limit)
{
	unsigned int	i;
	unsigned int	j;

	j = strlen(to_format);
	i = 0;
	if (! limit)
		limit = UINT_MAX;
	while (i < limit && *(base_string + i))
	{
		if (! space_or_tab(*(base_string + i)))
		{
			*(to_format + j) = *(base_string + i);
			j ++;
		}
		else if (! space_or_tab(*(base_string + i + 1)))
		{
			*(to_format + j) = ' ';
			j ++;
		}
		i ++;
	}
	return (j);
}

static unsigned int	fill_prototype(char *to_format, \
const char *prototype, unsigned int end_of_types, \
const unsigned int tabs_number)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = add_formated_string(to_format, prototype, end_of_types);
	while (isspace(*(prototype + end_of_types)))
		end_of_types++;
	while (i++ < tabs_number)
	{
		*(to_format + j) = '\t';
		j ++;
	}
	return (add_formated_string(to_format, \
	prototype + end_of_types, 0));
}

char	*format_prototype(const char *prototype, const unsigned int max_distance, unsigned int *prototype_len)
{
	char			*formated_proto;
	unsigned int	len;
	unsigned int	tabs_number;
	unsigned int	end_of_types;

	len = proto_length(prototype, max_distance, &end_of_types, &tabs_number);
	if (! len)
		return (NULL);
	formated_proto = calloc(len + 1, sizeof * formated_proto);
	if (! formated_proto)
		return (NULL);
	*prototype_len = len;
	fill_prototype(formated_proto, prototype, end_of_types, tabs_number);
	return (formated_proto);
}
