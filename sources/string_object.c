/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:00:21 by nsainton          #+#    #+#             */
/*   Updated: 2023/08/04 16:19:22 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

size_t	tstrncat(struct s_str *str, const char *s, size_t bytes)
{
	size_t	added;
	size_t	i;

	if (str->len >= str->size - 1)
		return (0);
	if (bytes + str->len >= str->size - 1)
		bytes = str->size - str->len - 1;
	added = bytes;
	i = 0;
	while (i < bytes && *(s + i))
	{
		*(str->str + str->len) = *(s + i);
		str->len += 1;
		i ++;
	}
	*(str->str + str->len) = 0;
	return (added);
}

struct s_str	*tstr_realloc(struct s_str *old_string, size_t new_size)
{
	struct s_str	*new_string;

	new_string = calloc(1, sizeof * new_string);
	if (new_string == NULL)
		return (NULL);
	new_string->str = calloc(1, new_size);
	if (new_string->str == NULL)
	{
		free(new_string);
		return (NULL);
	}
	new_string->size = new_size;
	new_string->len = MIN(old_string->len, new_size - 1);
	memmove(new_string->str, old_string->str, new_string->len);
	free(old_string->str);
	free(old_string);
	return (new_string);
}

void	tstr_reinit(struct s_str *str)
{
	if (str->str != NULL)
		free(str->str);
	bzero(str, sizeof * str);
}

int	tstr_init(struct s_str *str, size_t size)
{
	if (! size)
		return (EXIT_FAILURE);
	bzero(str, sizeof * str);
	str->str = calloc(size, sizeof * str->str);
	if (! str->str)
		return (EXIT_FAILURE);
	str->size = size;
	return (EXIT_SUCCESS);
}

void	tstr_del(struct s_str *str)
{
	if (str->size > 0)
		free(str->str);
	free(str);
}
