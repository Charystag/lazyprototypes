/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:30:49 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/28 02:45:37 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	dst_len;

	dst_len = ft_strlen(dest);
	i = 0;
	while (i < n && *(src + i))
	{
		*(dest + dst_len + i) = *(src + i);
		i ++;
	}
	*(dest + dst_len + i) = 0;
	return (i);
}
