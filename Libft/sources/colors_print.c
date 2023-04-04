/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 03:35:42 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/31 09:45:03 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_color_string(t_cvoid *s, t_cchar *color, t_cint fd)
{
	return (ft_dprintf(fd, "%s%s%s", color, (t_cchar *)s, CRESET));
}

int	print_color_number(t_cvoid *nb, t_cchar *color, t_cint fd)
{
	return (ft_dprintf(fd, "%s%d%s", color, *(t_cint *)nb, CRESET));
}

t_colorfunc	chose_function(t_cint type)
{
	t_colorfunc	print_color[128];

	print_color['d'] = print_color_number;
	print_color['s'] = print_color_string;
	return (print_color[type]);
}

int	print_color(t_cvoid *s, t_cint type, t_cchar *color, t_cint fd)
{
	t_colorfunc	print_color;

	print_color = chose_function(type);
	return (print_color(s, color, fd));
}

/*
Think about using generic selection for colors
*/

int	print_colors(t_cvoid **s, t_cint *type, t_cchar **colors, t_cint *infos)
{
	int	fd;
	int	size;
	int	i;
	int	printed;

	fd = *infos;
	size = *(infos + 1);
	i = 0;
	printed = 0;
	while (i < size)
	{
		printed += \
		print_color(*(s + i), *(type + i), *(colors + i), fd);
		i ++;
	}
	return (printed);
}
