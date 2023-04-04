/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_addelem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:32:21 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/28 10:30:19 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(*new_elem));
	if (new_elem == NULL)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	new_elem->priority = 0;
	return (new_elem);
}

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
