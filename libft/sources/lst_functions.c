/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:37:10 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/28 16:33:36 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_clist *lst)
{
	int	size;

	if (lst == NULL)
		return (0);
	size = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		size ++;
	}
	return (size);
}

t_list	*ft_lstlast(t_clist *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return ((t_list *)lst);
}

void	ft_lstiter(t_list *lst, void (*f) (void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*newlist;
	t_list	*newelem;

	newlist = ft_lstnew(f(lst->content));
	if (newlist == NULL)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		newelem = ft_lstnew(f(lst->content));
		if (newelem == NULL)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newelem);
		lst = lst-> next;
	}
	return (newlist);
}
