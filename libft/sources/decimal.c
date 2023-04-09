/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:31:17 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/26 21:03:54 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_pos(t_ull nb, char **tab, char *base)
{
	t_ull	i;

	i = (t_ull)ft_strlen(base);
	if (nb < i)
	{
		**tab = *(base + nb);
		*tab += 1;
	}
	else
	{
		put_pos(nb / i, tab, base);
		put_pos(nb % i, tab, base);
	}
}

void	put_dec(t_pbuffer *buf, va_list *ap, char flags[128])
{
	int		len;
	int		arg;
	char	nb[12];
	char	*tmp;

	tmp = nb;
	arg = va_arg(*ap, int);
	put_pos(abs_ll((t_ll)arg), &tmp, DEC);
	len = (int)(tmp - nb);
	*tmp = 0;
	if (!(arg || buf->prec) && flags['.'])
	{
		*nb = 0;
		len = 0;
	}
	if (arg < 0)
		flags['m'] = 1;
	build_res(buf, nb, flags, len);
}

void	put_unsigned(t_pbuffer *buf, va_list *ap, char flags[128])
{
	int				len;
	unsigned int	arg;
	char			nb[12];
	char			*tmp;

	tmp = nb;
	arg = va_arg(*ap, unsigned int);
	put_pos(abs_ll((t_ll)arg), &tmp, DEC);
	len = (int)(tmp - nb);
	*tmp = 0;
	if (!(arg || buf->prec) && flags['.'])
	{
		*nb = 0;
		len = 0;
	}
	build_res(buf, nb, flags, len);
}
