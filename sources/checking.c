/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:02:08 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/30 15:50:19 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	space_or_tab(int c)
{
	return (c == ' ' || c == '\t');
}

size_t	tabslen(t_cchar *line)
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
	return (len + (TABLEN - 1) * tabs);
}

size_t	tabsnlen(t_cchar *line, const size_t n)
{
	size_t	tabs;
	size_t	len;

	tabs = 0;
	len = 0;
	while (len < n && *(line + len))
	{
		tabs += (*(line + len) == '\t');
		len++;
	}
	return (len + (TABLEN - 1) * tabs);
}

int	comment_switch(const char *line, int *swit, size_t len)
{
	t_cchar	*beg;
	t_cchar	*end;

	beg = ft_strnstr(line, CBEG, len);
	end = ft_strnstr(line, CEND, len);
	*swit += (beg != NULL);
	if (end)
		*swit -= (*swit != 0);
	return (*swit);
}
