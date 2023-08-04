/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_codeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:03:43 by nsainton          #+#    #+#             */
/*   Updated: 2023/08/04 16:33:26 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

/*
	We check for nread + len + 3 to keep two slots available for the
	semicolomn and the line return if we encountered a function prototype
*/
static int	addline(struct s_str **buff, char *buffer, size_t nread, \
int *continued)
{
	struct s_str	*tmp;

	if (nread + (*buff)->len + 3 > (*buff)->size)
	{
		tmp = tstr_realloc(*buff, 2 * (*buff)->size);
		if (tmp == NULL)
			return (EXIT_FAILURE);
		*buff = tmp;
	}
	if ((nread > 1 && *(buffer + nread - 2) != '\\') || nread == 1)
		*continued = 0;
	else
		*(buffer + nread - 2) = 0;
	tstrncat(*buff, buffer, nread);
	return (EXIT_SUCCESS);
}

static int	init_args(char **buffer, size_t *linesize, \
struct s_str *buf, int *continued)
{
	*buffer = NULL;
	*linesize = 0;
	*continued = 1;
	tstr_reinit(buf);
	return (tstr_init(buf, BUFF_SIZE));
}

int	get_codeline(struct s_str **buff, FILE *fstream)
{
	size_t			linesize;
	ssize_t			nread;
	char			*buffer;
	int				continued;

	if (init_args(&buffer, &linesize, *buff, &continued))
		return (EXIT_FAILURE);
	nread = getline(&buffer, &linesize, fstream);
	while (nread > 0 && continued)
	{
		if (addline(buff, buffer, (size_t)nread, &continued) == EXIT_FAILURE)
		{
			free(buffer);
			return (EXIT_FAILURE);
		}
		if (continued)
			nread = getline(&buffer, &linesize, fstream);
	}
	free(buffer);
	return ((nread < 0) * EXIT_FAILURE);
}
