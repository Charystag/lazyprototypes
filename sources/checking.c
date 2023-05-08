/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:02:08 by nsainton          #+#    #+#             */
/*   Updated: 2023/05/08 15:50:39 by nsainton         ###   ########.fr       */
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

void	comment_switch(const char *line, char *swit, size_t len)
{
	t_cchar	*beg;
	t_cchar	*end;

	beg = ft_strnstr(line, CBEG, len);
	end = ft_strnstr(line, CEND, len);
	if (end)
		*swit -= (*swit != 0);
	*swit += (beg != NULL);
}
