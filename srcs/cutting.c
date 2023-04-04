/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cutting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:11:52 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/31 17:18:58 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static size_t	next_coma(t_cchar *line, const size_t max)
{
	char	*coma;
	size_t	next_coma;

	//printf("Line : %s\n", line);
	coma = strchr(line, ',');
	next_coma = 0;
	while (coma && (size_t)(coma - line) < max)
	{
		next_coma = coma - line;
		coma = strchr(line + next_coma + 1, ',');
	}
	return (next_coma + 2);
}

void	cat_line_ret(char *new_line, t_cchar *line, size_t max)
{
	int		index;
	size_t	coma;

	index = 0;
	while (strlen(line) > max)
	{
		if (index > 5)
			return ;
		coma = next_coma(line, max);
		strncat(new_line, line, coma);
		strcat(new_line, "\\\n");
		line += coma;
		//dprintf(STDERR_FILENO, "Len : %ld | max : %ld\n", len, max + coma);
		index ++;
	}
	strcat(new_line, line);
}
