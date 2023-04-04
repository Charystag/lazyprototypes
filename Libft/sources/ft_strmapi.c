/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:40:45 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/19 10:20:46 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*ns;

	if (s == NULL || f == NULL)
		return (NULL);
	ns = (char *)malloc((ft_strlen(s) + 1) * sizeof(*ns));
	if (ns == NULL)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(ns + i) = f(i, *(s + i));
		i ++;
	}
	*(ns + i) = 0;
	return (ns);
}
