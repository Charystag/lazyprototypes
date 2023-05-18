/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:53:19 by nsainton          #+#    #+#             */
/*   Updated: 2023/05/18 17:34:14 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*str_uppercase(t_cchar *str)
{
	char	*ns;
	size_t	index;

	ns = malloc ((strlen(str) + 1) * sizeof * ns);
	if (! ns)
		return (ns);
	index = 0;
	while (*(str + index))
	{
		if (*(str + index) != '.')
			*(ns + index) = toupper(*(str + index));
		else
			*(ns + index) = '_';
		index ++;
	}
	*(ns + index) = 0;
	return (ns);
}

static char *name_int(t_cchar *str)
{
	char	*ns;
	char	*last_dot;

	ns = calloc((strlen(str) + strlen(INT) + 4), sizeof * ns);
	if (! ns)
		return (ns);
	last_dot = strrchr(str, '.');
	if (! last_dot)
	{
		free(ns);
		return (NULL);
	}
	strcat(ns, "\"");
	strncpy(ns + 1, str, last_dot - str);
	strcat(ns, INT);
	strcat(ns, ".h\"");
	return (ns);
}

int	write_header_prot(t_cint fd, t_cchar *str)
{
	char	*upper;
	char	*header;
	int		error;

	if (! (upper = str_uppercase(str)))
		return (1);
	if (! (header = malloc(2 * strlen(upper) + strlen(IND) + strlen(D) + 4)))
	{
		free(upper);
		return (1);
	}
	*header = 0;
	strcat(header, IND);
	strcat(header, upper);
	strcat(header, "\n");
	strcat(header, D);
	strcat(header, upper);
	strcat(header, "\n");
	free(upper);
	error = (write(fd, header, strlen(header)) < 1);
	if (error)
	{
		dprintf(DEBUG_OUT, "Error encountered in function : %s\n", __func__);
		return (1);
	}
	free(header);
	upper = name_int(str);
	if (! upper)
	{
		dprintf(DEBUG_OUT, "Error encountered in function : %s\n", __func__);
		return (1);
	}
	header = malloc((strlen(upper) + strlen(INC) + 4) * sizeof * header);
	if (! header)
	{
		free(upper);
		dprintf(DEBUG_OUT, "Error encountered in function : %s\n", __func__);
		return (1);
	}
	*header = 0;
	strcat(header, INC);
	strcat(header, upper);
	strcat(header, "\n\n");
	free(upper);
	if ((write(fd, header, strlen(header)) < 1))
	{
		dprintf(DEBUG_OUT, "Error encountered in function : %s\n", __func__);
	}
	free(header);
	return (error);
}
