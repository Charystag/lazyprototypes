/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:02:18 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/14 15:41:28 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digits(int n)
{
	unsigned int	nbr;
	size_t			dig;

	if (! n)
		return (1);
	dig = 0;
	if (n < 0)
	{
		dig ++;
		nbr = (unsigned int)(-1 * n);
	}
	else
		nbr = (unsigned int)n;
	while (nbr)
	{
		nbr /= 10;
		dig ++;
	}
	return (dig);
}

static void	ft_itoa_rec(int n, char *number, int *index)
{
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = (unsigned int)(-1 * n);
		*(number + *index) = 45;
		*index += 1;
		if (nbr / 10)
			ft_itoa_rec((int)(nbr / 10), number, index);
		ft_itoa_rec((int)(nbr % 10), number, index);
	}
	else if (n < 10)
	{
		*(number + *index) = n + 48;
		*index += 1;
	}
	else
	{
		ft_itoa_rec(n / 10, number, index);
		ft_itoa_rec(n % 10, number, index);
	}
}

char	*ft_itoa(int n)
{
	char	*number;
	size_t	dig;
	int		index;

	dig = ft_digits(n);
	number = (char *)ft_calloc(dig + 1, sizeof(*number));
	if (number == NULL)
		return (NULL);
	*(number + dig) = 0;
	index = 0;
	ft_itoa_rec(n, number, &index);
	return (number);
}
