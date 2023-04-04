/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:18:12 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/05 06:32:32 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;

	if (dst == NULL || ! size)
		return (ft_strlen(src));
	if (src == NULL)
		return (ft_strlen(dst));
	len_dst = 0;
	while (*(dst + len_dst) && len_dst < size)
		len_dst ++;
	len_src = 0;
	while (*(src + len_src) && (len_dst + len_src < size - 1))
	{
		*(dst + len_dst + len_src) = *(src + len_src);
		len_src ++;
	}
	if (len_dst < size)
		*(dst + len_dst + len_src) = 0;
	while (*(src + len_src))
		len_src ++;
	return (len_src + len_dst);
}
