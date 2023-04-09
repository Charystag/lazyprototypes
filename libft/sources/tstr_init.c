/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstr_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:47:28 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/12 03:11:31 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tstr_init(t_str *str)
{
	if (str->str != NULL)
		free(str->str);
	ft_bzero(str, sizeof * str);
}

int	tstr_initstr(t_str *tstr, char *str, size_t buffsize)
{
	size_t	len;
	size_t	size;

	if (str == NULL)
		str = "";
	len = ft_strlen(str);
	size = len + 1;
	if (size < buffsize)
		size = buffsize;
	tstr->str = ft_calloc(size, sizeof *(tstr->str));
	if (tstr->str == NULL)
	{
		tstr_init(tstr);
		return (1);
	}
	ft_strlcpy(tstr->str, str, size);
	tstr->len = len;
	tstr->size = size;
	return (0);
}

int	tstr_cpy(t_str *dst, const t_str *src)
{
	if (dst->size > 0)
		free(dst->str);
	dst->str = ft_calloc(src->size, 1);
	if (dst->str == NULL)
	{
		tstr_init(dst);
		return (1);
	}
	ft_strlcpy(dst->str, src->str, src->size);
	dst->size = src->size;
	dst->len = src->len;
	return (0);
}
