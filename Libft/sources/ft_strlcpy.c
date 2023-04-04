/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:06:55 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/27 04:55:31 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (! size)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && *(src + i))
	{
		*(dst + i) = *(src + i);
		i ++;
	}
	*(dst + i) = 0;
	while (*(src + i))
		i ++;
	return (i);
}
