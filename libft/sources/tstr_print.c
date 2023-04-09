/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 07:08:18 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/28 21:58:46 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tstr_print(t_str *str)
{
	write(STDOUT_FILENO, str->str, str->len);
}

void	tstr_print_fd(t_str *str, int fd)
{
	write(fd, str->str, str->len);
}
