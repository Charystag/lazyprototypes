/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:02:08 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/04 14:40:54 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
