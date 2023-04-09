/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:30:47 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/27 03:53:39 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_uns_tab(t_ull nb, char **tab, char *base, size_t len)
{
	if (nb < len)
	{
		**tab = *(base + nb);
		*tab += 1;
		**tab = 0;
	}
	else
	{
		put_uns_tab(nb / len, tab, base, len);
		put_uns_tab(nb % len, tab, base, len);
	}
}

void	put_nb_tab(t_ll nb, char *tab, char *base)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(base);
	tmp = tab;
	if (nb < 0)
	{
		*tmp = '-';
		tmp += 1;
		put_uns_tab((t_ull)(-1 * nb), &tmp, base, len);
	}
	else
		put_uns_tab(nb, &tmp, base, len);
}
