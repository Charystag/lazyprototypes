/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 03:18:11 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/11 02:13:47 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list	ap;
	int		ret;
	t_str	tstr;

	va_start(ap, format);
	tstr = (t_str){str, 0, size};
	ret = ft_vsnprintf(&tstr, format, ap);
	va_end(ap);
	return (ret);
}

int	ft_sprintf(t_str *str, const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vsnprintf(str, format, ap);
	va_end(ap);
	return (ret);
}

int	ft_vsnprintf(t_str *str, const char *format, va_list ap)
{
	t_pbuffer	buf;
	const char	*s;
	char		flags[128];
	va_list		cpy;

	va_copy(cpy, ap);
	s = format;
	init_pbuf_str(&buf, str);
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
