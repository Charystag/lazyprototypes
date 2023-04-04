/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstr_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:08:40 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/14 03:57:34 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	*tstr_realloc(t_str *old_string, size_t new_size)
{
	t_str	*new_string;

	new_string = ft_calloc(1, sizeof * new_string);
	if (new_string == NULL)
	{
		free(old_string->str);
		free(old_string);
		return (NULL);
	}
	new_string->str = ft_calloc(1, new_size);
	if (new_string->str == NULL)
	{
		free(new_string);
		free(old_string->str);
		free(old_string);
		return (NULL);
	}
	new_string->size = new_size;
	new_string->len = ft_minst(old_string->len, new_size - 1);
	ft_memmove(new_string->str, old_string->str, new_string->len);
	free(old_string->str);
	free(old_string);
	return (new_string);
}
