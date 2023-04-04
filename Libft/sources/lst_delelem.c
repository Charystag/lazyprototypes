/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delelem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:12:24 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/23 09:51:55 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del) (void *))
{
	del(lst->content);
	free(lst);
}

static void	ft_lstfreenodes(t_list **lst)
{
	t_list	*p;
	t_list	*q;

	p = *lst;
	while (p->next)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(p);
	*lst = NULL;
}

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*p;
	t_list	*q;

	p = *lst;
	if (p == NULL)
		return ;
	if (! del)
		return (ft_lstfreenodes(lst));
	while (p->next != NULL)
	{
		q = p->next;
		del(p->content);
		free(p);
		p = q;
	}
	del(p->content);
	free(p);
	*lst = NULL;
}

void	ft_lstdel_front(t_list **lst, void (*del) (void *))
{
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	if (del)
		return (ft_lstdelone(tmp, del));
	free(tmp);
}
