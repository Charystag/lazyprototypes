/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:09:12 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/09 12:12:43 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	unsigned int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (*(s + i))
	{
		f(i, s + i);
		i ++;
	}
}
