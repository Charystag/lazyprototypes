/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:35:45 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/13 13:01:47 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*ns;

	if (! (s1 || s2))
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ns = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(*ns));
	if (ns == NULL)
		return (NULL);
	*ns = 0;
	ft_strlcat(ns, s1, len_s1 + len_s2 + 1);
	ft_strlcat(ns + len_s1, s2, len_s2 + 1);
	return (ns);
}
