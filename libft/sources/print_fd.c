/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:46:24 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/12 05:28:33 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd(t_cchar c, t_cint fd)
{
	return ((int)write(fd, &c, 1));
}

int	ft_putstr_fd(t_cchar *s, t_cint fd)
{
	size_t	i;

	i = ft_strlen(s);
	return ((int)write(fd, s, i));
}

int	ft_putendl_fd(t_cchar *s, t_cint fd)
{
	int	written;

	written = ft_putstr_fd(s, fd);
	if (written == -1)
		return (-1);
	if (ft_putchar_fd('\n', fd) == -1)
		return (-1);
	return (written + 1);
}

int	ft_putnbr_fd(t_cint n, t_cint fd)
{
	char	c[12];

	put_nb_tab((t_ll)n, c, DEC);
	return (ft_putstr_fd(c, fd));
}
