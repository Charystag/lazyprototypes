/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstr_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:34:33 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/28 21:55:44 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	tstr_addchar(t_str *str, char c)
{
	if (str->len >= str->size - 1)
		return (1);
	*(str->str + str->len) = c;
	str->len += 1;
	*(str->str + str->len) = 0;
	return (0);
}

size_t	tstrncat(t_str *str, const char *s, size_t bytes)
{
	size_t	added;

	if (str->len >= str->size - 1)
		return (0);
	if (bytes + str->len >= str->size - 1)
		bytes = str->size - str->len - 1;
	added = bytes;
	while (bytes > 0 && *s)
	{
		*(str->str + str->len) = *s;
		s ++;
		str->len += 1;
		bytes --;
	}
	*(str->str + str->len) = 0;
	return (added);
}
