/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:53:02 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/31 05:28:39 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*ns;

	i = ft_strlen(s);
	ns = ft_calloc(i + 1, sizeof * ns);
	if (ns == NULL)
		return (NULL);
	ft_memmove(ns, s, i + 1);
	return (ns);
}
