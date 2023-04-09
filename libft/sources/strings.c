/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 03:57:04 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/26 21:05:44 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_len(t_pbuffer *buf, char flags[128], int *len, char *res)
{
	if (flags['.'] && buf->prec < 6)
		*len = 0;
	else
		*len = ft_strlcat(res, "(null)", 7);
}

void	put_char(t_pbuffer *buf, va_list *ap, char flags[128])
{
	char	align;
	char	arg;

	arg = (char)va_arg(*ap, int);
	align = 'r';
	if (flags['-'])
		align = 'l';
	if (align == 'r')
		add_nchar(buf, ' ', buf->width - 1);
	add_char(buf, arg);
	if (align == 'l')
		add_nchar(buf, ' ', buf->width - 1);
}

void	put_string(t_pbuffer *buf, va_list *ap, char flags[128])
{
	int		len;
	char	*arg;
	char	null[7];
	t_print	pads;

	arg = va_arg(*ap, char *);
	*null = 0;
	if (arg == NULL)
		set_len(buf, flags, &len, null);
	else if (flags['.'])
		len = ft_strnlen(arg, (size_t)buf->prec);
	else
		len = ft_strlen(arg);
	set_pad(flags, &pads);
	buf->prec = len;
	pads.beg = 0;
	pads.pad = ' ';
	if (arg != NULL)
		print_res(buf, arg, len, &pads);
	else
		print_res(buf, null, len, &pads);
}
