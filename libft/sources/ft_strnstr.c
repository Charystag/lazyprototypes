/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:30:10 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/27 02:26:30 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_search_from(const char *s1, const char *s2, size_t n, \
size_t from)
{
	size_t	j;

	j = 0;
	while (from + j < n && *(s1 + from + j) && *(s2 + j))
	{
		if (*(s1 + from + j) != *(s2 + j))
			return (0);
		j ++;
	}
	if (! *(s2 + j))
		return (1);
	return (0);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (*s2 == 0)
		return ((char *)(s1));
	i = 0;
	while (*(s1 + i))
	{
		if (i >= n)
			break ;
		if (ft_search_from(s1, s2, n, i))
			return ((char *)(s1 + i));
		i ++;
	}
	return (NULL);
}
