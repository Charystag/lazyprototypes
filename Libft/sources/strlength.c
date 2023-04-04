/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlength.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:17:59 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/14 22:44:08 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
		ptr ++;
	return (ptr - s);
}

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	i;

	i = 0;
	while (i < maxlen && *(s + i))
		i ++;
	return (i);
}
