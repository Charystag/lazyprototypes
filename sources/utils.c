/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:09:26 by nsainton          #+#    #+#             */
/*   Updated: 2023/08/04 16:11:23 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>

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

/*
	To prevent integer promotion from hapenning too often and to comply with
	historical reasons for which char function takes and return an integer
	the function to be applied is a function that takes and return an integer
*/
char	*ft_strmapi(char const *s, int (*f) (unsigned int, int))
{
	unsigned int	i;
	char			*ns;

	if (s == NULL || f == NULL)
		return (NULL);
	ns = malloc((strlen(s) + 1) * sizeof * ns);
	if (ns == NULL)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(ns + i) = f(i, *(s + i));
		i ++;
	}
	*(ns + i) = 0;
	return (ns);
}

size_t	ft_strcat(char *dest, const char *src)
{
	size_t	dest_len;
	size_t	i;

	dest_len = strlen(dest);
	i = 0;
	while (*(src + i))
	{
		*(dest + dest_len + i) = *(src + i);
		i ++;
	}
	*(dest + dest_len + i) = 0;
	return (dest_len + i);
}
