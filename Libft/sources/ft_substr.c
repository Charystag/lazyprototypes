/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:56:16 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/13 12:14:25 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(const char *s, unsigned int start, size_t len)
{
	size_t	length;

	length = ft_strlen(s);
	if (start >= length)
		return (0);
	if (len > length - start)
		return (length - start);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*ns;

	if (s == NULL)
		return (NULL);
	size = ft_min(s, start, len);
	ns = (char *)malloc((size + 1) * sizeof(*ns));
	if (ns == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(ns + i) = *(s + start + i);
		i ++;
	}
	*(ns + i) = 0;
	return (ns);
}
