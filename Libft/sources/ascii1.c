/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:03:47 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/26 22:09:08 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

int	ft_isascii(int c)
{
	return ((c > -1 && c < 128));
}

int	ft_isdigit(int c)
{
	return ((c > 47 && c < 58));
}

int	ft_isprint(int c)
{
	return ((c > 31 && c < 127));
}

int	ft_isspace(int c)
{
	return ((c == 32 || (c > 8 && c < 14)));
}
