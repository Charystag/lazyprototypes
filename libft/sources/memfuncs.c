/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memfuncs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:39:04 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/27 02:16:09 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ns;
	size_t				i;

	ns = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(ns + i) == (unsigned char)c)
			return ((void *)(s + i));
		i ++;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ptrs[2];

	ptrs[0] = (const unsigned char *)s1;
	ptrs[1] = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*(*ptrs + i) != *(*(ptrs + 1) + i))
			break ;
		i ++;
	}
	if (i == n)
		return (0);
	return ((int)(*(*ptrs + i) - *(*(ptrs + 1) + i)));
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;

	i = 0;
	while (i < n)
	{
		*((char *)(dest + i)) = *((char *)(src + i));
		i ++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	size_t			count;
	int				direction;

	i = 0;
	direction = 1;
	count = 0;
	if (dest > src)
	{
		i = n - 1;
		direction = -1;
	}
	while (count < n)
	{
		*((char *)(dest + i)) = *((char *)(src + i));
		i += direction;
		count ++;
	}
	return (dest);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	letter;

	str = (unsigned char *)b;
	letter = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		*(str + i) = letter;
		i ++;
	}
	return (b);
}
