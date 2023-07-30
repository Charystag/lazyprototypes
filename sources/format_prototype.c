/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_prototype.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 10:50:03 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/30 11:21:27 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static unsigned int	proto_length(const char *prototype, \
const unsigned int max_distance)
{
	char			*parenthesis;
	char			*func_name;
	unsigned int	distance;
	unsigned int	tabs_number;

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
	distance = compute_distance(prototype, (parenthesis - prototype));
	tabs_number = (max_distance / TABLEN + distance / TABLEN + 1);
	return (distance + tabs_number + strlen(func_name) + 1);
}

char	*format_prototype(const char *prototype)
{
	char			*formated_proto;
	unsigned int	len;
