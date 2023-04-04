/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:48:55 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/19 17:57:07 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *(s1 + i) && *(s2 + i))
	{
		if (*(s1 + i) != *(s2 + i))
			break ;
		i ++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}

int	ft_strcmp(t_cchar *s1, t_cchar *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1 ++;
		s2 ++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	cmp_until(t_cchar *s1, t_cchar *s2, t_cchar c)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) && *(s2 + i) && *(s1 + i) != c && *(s2 + i) != c)
	{
		if (*(s1 + i) != *(s2 + i))
			break ;
		i ++;
	}
	if (*(s1 + i) == c || *(s2 + i) == c)
		return (0);
	return ((t_uchar) *(s1 + i) - (t_uchar) *(s2 + i));
}
