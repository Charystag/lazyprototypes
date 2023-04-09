/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:07:48 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/11 02:30:20 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vdprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (ret);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_pbuffer	buf;
	const char	*s;
	char		flags[128];
	va_list		cpy;

	va_copy(cpy, ap);
	s = format;
	init_pbuf_fd(&buf, fd);
	while (*s)
	{
		loop(&buf, &s);
		if (! *s)
			break ;
		parse_conv(&buf.width, &buf.prec, &s, flags);
		add_conv(&s, &buf, &cpy, flags);
		if (buf.printed == -1)
			break ;
	}
	flush(&buf);
	return (buf.printed);
}
