/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:02:08 by nsainton          #+#    #+#             */
/*   Updated: 2023/08/04 15:56:29 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	space_or_tab(int c)
{
	return (c == ' ' || c == '\t');
}

size_t	tabslen(const char *line)
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

size_t	tabsnlen(const char *line, const size_t n)
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
	const char	*beg;
	const char	*end;

	beg = ft_strnstr(line, CBEG, len);
	end = ft_strnstr(line, CEND, len);
	*swit += (beg != NULL);
	if (end)
		*swit -= (*swit != 0);
	return (*swit);
}
