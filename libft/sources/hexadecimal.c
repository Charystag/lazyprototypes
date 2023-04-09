/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 04:41:25 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/26 21:04:45 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_hpad(char res[19], char flags[128], t_print *pads, char min)
{
	*(pads->modifier) = 0;
	pads->beg = 0;
	pads->pad = ' ';
	pads->align = 'r';
	if (flags[48] && ! flags['.'])
		pads->pad = 48;
	if (flags['-'])
		pads->align = 'l';
	if (! (flags['#'] && *res) || *res == 48)
		return ;
	if (min)
		ft_strlcat(pads->modifier, "0x", 3);
	else
		ft_strlcat(pads->modifier, "0X", 3);
}

static void	build_hres(t_pbuffer *buf, char res[19], char flags[128], char min)
{
	t_print	pads;
	int		len;

	set_hpad(res, flags, &pads, min);
	len = (int)ft_strlen(res);
	buf->prec = max_int(buf->prec, len);
	buf->width = max_int(buf->width, buf->prec);
	print_res(buf, res, len, &pads);
}

static void	put_hex(t_pbuffer *buf, va_list *ap, char flags[128], char min)
{
	char	res[19];
	t_ull	arg;
	char	*tmp;

	tmp = res;
	*tmp = 0;
	arg = (t_ull)va_arg(*ap, unsigned int);
	if (min)
		put_pos(arg, &tmp, HEX);
	else
		put_pos(arg, &tmp, HEX_MAJ);
	*tmp = 0;
	if (!(arg || buf->prec) && flags['.'])
		*res = 0;
	build_hres(buf, res, flags, min);
}

void	put_hex_min(t_pbuffer *buf, va_list *ap, char flags[128])
{
	put_hex(buf, ap, flags, 1);
}

void	put_hex_maj(t_pbuffer *buf, va_list *ap, char flags[128])
{
	put_hex(buf, ap, flags, 0);
}
