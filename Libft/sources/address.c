/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:26:46 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/26 22:18:26 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	build_address(t_pbuffer *buf, va_list *ap, char res[19], int *len)
{
	t_ull	arg;
	char	*tmp;

	arg = (t_ull)va_arg(*ap, void *);
	*res = 0;
	if (!arg)
		*len = ft_strlcat(res, "(nil)", 19);
	else
	{
		ft_strlcat(res, "0x", 19);
		tmp = res + 2;
		put_pos(arg, &tmp, HEX);
		*tmp = 0;
		*len = (int)(tmp - res);
	}
	buf->prec = *len;
}

void	put_address(t_pbuffer *buf, va_list *ap, char flags[128])
{
	int		len;
	t_print	pads;
	char	res[19];

	build_address(buf, ap, res, &len);
	set_pad(flags, &pads);
	pads.beg = 0;
	pads.pad = ' ';
	print_res(buf, res, len, &pads);
}
