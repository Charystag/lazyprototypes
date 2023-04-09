/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_equal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 01:01:31 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/11 02:07:37 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_equal(t_cchar *s1, t_cchar *s2)
{
	size_t	i;

	i = 0;
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			break ;
		i ++;
		s1 ++;
		s2 ++;
	}
	return (i);
}

t_llong	findlongestsubstr(t_cchar *haystack, t_cchar *needle)
{
	t_llong	index;
	size_t	longest;
	size_t	count;
	t_llong	loop_index;

	index = -1;
	longest = 0;
	count = 0;
	loop_index = 0;
	while (*(haystack + loop_index))
	{
		count = count_equal(haystack + loop_index, needle);
		if (count > longest)
		{
			index = loop_index;
			longest = count;
		}
		loop_index ++;
	}
	return (index);
}
