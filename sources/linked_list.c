/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:15:50 by nsainton          #+#    #+#             */
/*   Updated: 2023/08/04 16:57:14 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

struct s_list	*ft_lstnew_cpy(const void *content, size_t size)
{
	struct s_list	*new_elem;
	void	*new_content;

	new_content = malloc(size);
	if (! new_content)
		return (new_content);
	memcpy(new_content, content, size);
	new_elem = malloc(sizeof * new_elem);
	if (! new_elem)
	{
		free(new_content);
		return (new_elem);
	}
	bzero(new_elem, sizeof * new_elem);
	new_elem->content = new_content;
	return (new_elem);
}

void	ft_lstadd_front(struct s_list **lst, struct s_list *new)
{
	new->next = *lst;
	*lst = new;
}

static void	ft_lstfreenodes(struct s_list **lst)
{
	struct s_list	*p;
	struct s_list	*q;

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

void	ft_lstclear(struct s_list **lst, void (*del) (void *))
{
	struct s_list	*p;
	struct s_list	*q;

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

static void	ft_lstdelone(struct s_list *lst, void (*del) (void *))
{
	del(lst->content);
	free(lst);
}

void	ft_lstdel_front(struct s_list **lst, void (*del) (void *))
{
	struct s_list	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	if (del)
		return (ft_lstdelone(tmp, del));
	free(tmp);
}
