/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:38:01 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/28 21:57:16 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flush(t_pbuffer *buf)
{
	if (buf->str)
		flush_str(buf);
	else
		flush_fd(buf);
}

void	flush_fd(t_pbuffer *buf)
{
	int	printed;

	if (buf->printed == -1)
		return ;
	printed = (int)write(buf->fd, buf->buffer, buf->len);
	if (printed < 0)
		buf->printed = -1;
	else
		buf->printed += printed;
	buf->len = 0;
}

void	flush_str(t_pbuffer *buf)
{
	int		printed;
	t_str	*str;

	str = (t_str *)buf->fd;
	if (buf->printed == -1)
		return ;
	printed = (int)tstrncat(str, buf->buffer, buf->len);
	if (! (printed || buf->printed))
	{
		buf->printed = -1;
		return ;
	}
	buf->printed += printed;
	buf->len = 0;
}
