/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 08:32:51 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/04 01:06:47 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	char	*start;

	str = (char *)s;
	start = (char *)s;
	while ((size_t)(str - start) < n)
	{
		*str = 0;
		str ++;
	}
}
