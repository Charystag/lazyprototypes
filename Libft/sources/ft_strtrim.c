/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:13:44 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/23 21:34:40 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in(char c, char const *set)
{
	size_t	i;
	char	test;

	i = 0;
	test = *(set + i);
	while (test && test != c)
	{
		i ++;
		test = *(set + i);
	}
	if (test)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;

	if (set == NULL || ! *set)
		return (ft_strdup(s1));
	if (s1 == NULL)
		return (NULL);
	start = 0;
	while (ft_in(*(s1 + start), set))
		start ++;
	i = start;
	end = start;
	while (*(s1 + i))
	{
		if (!ft_in(*(s1 + i), set))
			end = i;
		i ++;
	}
	return (ft_substr(s1, start, end - start + 1));
}
