/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:22:56 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/02 06:25:09 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sint	ft_minint(t_sint a, t_sint b)
{
	if (a < b)
		return (a);
	return (b);
}

t_uint	ft_minuint(t_uint a, t_uint b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_minst(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}
