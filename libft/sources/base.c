/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 02:45:08 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/10 04:36:47 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isbase(t_cchar *s, t_csizet len)
{
	size_t	i;
	size_t	j;

	if (len < 2)
		return (0);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		if (ft_isspace(*(s + i)))
			return (0);
		while (j < len)
		{
			if (*(s + i) == *(s + j))
				return (0);
			j ++;
		}
		i ++;
	}
	return (1);
}

int	ft_atoi_base(t_cchar *s, t_cchar *base, t_csizet base_len)
{
	size_t	i;
	int		minus;
	int		res;
	t_cchar	*index;

	res = 0;
	i = 0;
	if (! isbase(base, base_len))
		return (0);
	while (ft_isspace(*(s + i)))
		i ++;
	if (*(s + i) == '+' || *(s + i) == '-')
		minus = (*(s + i++) == '+') * 2 - 1;
	else
		minus = 1;
	index = ft_strchr(base, *(s + i));
	while (*(s + i) && index)
	{
		res = res * base_len + index - base;
		i ++;
		index = ft_strchr(base, *(s + i));
	}
	return (minus * res);
}
