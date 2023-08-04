/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:15:50 by nsainton          #+#    #+#             */
/*   Updated: 2023/08/04 10:18:56 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*ft_lstnew_cpy(t_cvoid *content, size_t size)
{
	t_list	*new_elem;
	void	*new_content;

	new_content = malloc(size);
	if (! new_content)
		return (new_content);
	ft_memcpy(new_content, content, size);
	new_elem = malloc(sizeof * new_elem);
	if (! new_elem)
	{
		free(new_content);
		return (new_elem);
	}
	ft_bzero(new_elem, sizeof * new_elem);
	new_elem->content = new_content;
	return (new_elem);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = ft_lstlast(*lst);
	if (ptr == NULL)
		*lst = new;
	else
	{
		ptr->next = new;
		new->next = NULL;
	}
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
