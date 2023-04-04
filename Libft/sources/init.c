/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:02:41 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/10 03:56:36 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_pbuf_fd(t_pbuffer *buf, int fd)
{
	buf->fd = fd;
	buf->len = 0;
	buf->printed = 0;
	buf->width = 0;
	buf->prec = 0;
	buf->str = 0;
}

void	init_pbuf_str(t_pbuffer *buf, t_str *str)
{
	buf->fd = (intptr_t)str;
	buf->len = 0;
	buf->printed = 0;
	buf->width = 0;
	buf->prec = 0;
	buf->str = 1;
}

void	set_pad(char flags[128], t_print *pads)
{
	pads->beg = 0;
	pads->pad = ' ';
	pads->modifier[0] = 0;
	pads->align = 'r';
	if (flags[48] && ! flags['.'])
		pads->pad = 48;
	if (flags[32])
		pads->beg = 32;
	if (flags['+'])
		pads->beg = '+';
	if (flags['m'])
		pads->beg = '-';
	if (flags['-'])
		pads->align = 'l';
}

static void	init_func(t_pfunc func[80])
{
	size_t	len;

	len = ft_strlen(SPECIFIERS);
	func[ft_atoi_base("d", SPECIFIERS, len)] = &put_dec;
	func[ft_atoi_base("i", SPECIFIERS, len)] = &put_dec;
	func[ft_atoi_base("c", SPECIFIERS, len)] = &put_char;
	func[ft_atoi_base("u", SPECIFIERS, len)] = &put_unsigned;
	func[ft_atoi_base("s", SPECIFIERS, len)] = &put_string;
	func[ft_atoi_base("p", SPECIFIERS, len)] = &put_address;
	func[ft_atoi_base("x", SPECIFIERS, len)] = &put_hex_min;
	func[ft_atoi_base("X", SPECIFIERS, len)] = &put_hex_maj;
	func[ft_atoi_base("%", SPECIFIERS, len)] = &put_percent;
}

t_pfunc	*get_funcs(void)
{
	static t_pfunc	functions[80] = {0};
	size_t			len;

	len = ft_strlen(SPECIFIERS);
	if (functions[ft_atoi_base("d", SPECIFIERS, len)] == NULL)
		init_func(functions);
	return (functions);
}
