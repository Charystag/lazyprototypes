/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_access.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 22:07:01 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/07 19:30:56 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	setnext(t_list *node, t_list *next)
{
	node->next = next;
}

t_list	*getnext(t_clist *node)
{
	return (node->next);
}

void	setcontent(t_list *node, void *content)
{
	if (node->content)
		free(node->content);
	node->content = content;
}

void	*getcontent(t_clist *node)
{
	return (node->content);
}
