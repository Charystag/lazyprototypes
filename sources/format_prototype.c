/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_prototype.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 10:50:03 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/30 14:14:37 by nsainton         ###   ########.fr       */
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
		parenthesis --;
	}
	func_name = parenthesis;
	while (parenthesis != prototype)
	{
		if (isspace(*parenthesis) && !isspace(*(parenthesis - 1)))
			break ;
		parenthesis --;
	}
	*end_of_types = parenthesis - prototype;
	distance = compute_distance(prototype, *end_of_types);
	*tabs_number = (max_distance / TABLEN - distance / TABLEN + 1);
	return (distance + *tabs_number + strlen(func_name));
}

static void	fill_prototype(char *to_format, const char *prototype, \
unsigned int end_of_types)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < end_of_types)
	{
		if (! isspace(*(prototype + i)))
			*(to_format + j++) = *(prototype + i);
		else if (! isspace (*(prototype + i + 1)))
			*(to_format + j++) = ' ';
		i++;
	}
	while (isspace(*(prototype + end_of_types)))
		end_of_types++;
	strcpy(to_format + j, prototype + end_of_types);
}

char	*format_prototype(const char *prototype, const unsigned int max_distance)
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
	fill_prototype(formated_proto, prototype, end_of_types);
	return (formated_proto);
}
