/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:17:35 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/14 13:53:49 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_tab(char ***tab, size_t index)
{
	char	**p;

	p = *tab;
	if (p == NULL)
		return ;
	while (*(p + index))
	{
		free(*(p + index));
		index ++;
	}
	free(p);
	*tab = NULL;
}

static void	ft_find_bounds(const char *s, char c, size_t *start, size_t *end)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(s + i) && *(s + i) == c)
		i ++;
	while (*(s + i + j) && *(s + i + j) != c)
		j ++;
	*start = i;
	*end = j;
}

static int	ft_split_rec(const char *s, char c, char ***nt, size_t index)
{
	size_t	start;
	size_t	end;

	ft_find_bounds(s, c, &start, &end);
	if (! (start || end))
	{
		*nt = (char **)malloc((index + 1) * sizeof(char *));
		if (*nt == NULL)
			return (0);
		*(*nt + index) = NULL;
		return (1);
	}
	if (! end)
		return (ft_split_rec(s + start, c, nt, index));
	if (! ft_split_rec(s + start + end, c, nt, index + 1))
		return (0);
	*(*nt + index) = ft_substr(s + start, 0, end);
	if (*(*nt + index) != NULL)
		return (1);
	ft_free_tab(nt, index);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ns;

	if (s == NULL)
		return (NULL);
	ns = NULL;
	ft_split_rec(s, c, &ns, 0);
	return (ns);
}
