/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_structures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:32:51 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/01 20:28:18 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_STRUCTURES_H
# define LFT_STRUCTURES_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	int				priority;
}				t_list;

typedef struct s_pbuffer
{
	char			buffer[PBUFFER_SIZE];
	int				len;
	int				width;
	int				prec;
	intptr_t		fd;
	int				printed;
	unsigned char	str:1;
}				t_pbuffer;

typedef struct s_print
{
	char	modifier[3];
	char	beg;
	char	pad;
	char	align;
}				t_print;

typedef struct s_gline
{
	char	*line;
	size_t	line_index;
}				t_gline;

typedef struct s_str
{
	char	*str;
	size_t	len;
	size_t	size;
}				t_str;

#endif
