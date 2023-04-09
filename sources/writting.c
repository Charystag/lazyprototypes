/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:53:19 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/04 17:29:07 by nsainton         ###   ########.fr       */
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
	strcat(header, "\n\n");
	free(upper);
	error = (write(fd, header, strlen(header)) < 1);
	if (error)
		dprintf(DEBUG_OUT, "Error encountered in function : %s\n", __func__);
	free(header);
	return (error);
}
