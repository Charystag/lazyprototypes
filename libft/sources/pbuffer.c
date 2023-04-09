/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbuffer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:43:06 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/07 17:58:44 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_char(t_pbuffer *buf, char c)
{
	if (buf->len > PBUFFER_SIZE - 2)
		flush(buf);
	if (buf->printed == -1)
		return ;
	(buf->buffer)[buf->len] = c;
	buf->len += 1;
}

void	add_nchar(t_pbuffer *buf, char c, int n)
{
	while (n > 0)
	{
		add_char(buf, c);
		if (n % 100 == 0 && buf->printed == -1)
			return ;
		n --;
	}
}

void	add_str(t_pbuffer *buf, char *str)
{
	if (str == NULL)
		return ;
	while (*str)
	{
		add_char(buf, *str);
		str ++;
	}
}

void	add_nstr(t_pbuffer *buf, char *str, int n)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (i < n && *(str + i))
	{
		add_char(buf, *(str + i));
		i ++;
	}
}

void	add_conv(t_cchar **s, t_pbuffer *buf, va_list *cpy, char flags[128])
{
	t_pfunc	*func;
	size_t	len;
	int		index;
	t_ll	nbr;
	char	*admitted;

	if (**s == '%')
	{
		put_percent(buf, cpy, flags);
		*s += 1;
		return ;
	}
	func = get_funcs();
	len = ft_strlen(P_CONV);
	nbr = findlongestsubstr(ADMITTED, *s);
	admitted = ADMITTED;
	if (nbr < 0)
		return ;
	index = ft_atoi_base(admitted + nbr, P_CONV, len);
	func[index](buf, cpy, flags);
	*s += index / len + 1;
}
