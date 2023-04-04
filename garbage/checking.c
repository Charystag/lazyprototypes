/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:40:43 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/04 14:40:49 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_path_char(int c)
{
	return (isalnum(c) || c == '.' || c == '/' || c == '_' || c == '-');
}

int	valid_path(t_cchar *path)
{
	while (*path)
	{
		if (! is_path_char(*path))
		{
			dprintf(STDERR_FILENO, "This is the problematic char : %c\n", *path);
			return (0);
		}
		path ++;
	}
	return (1);
}
