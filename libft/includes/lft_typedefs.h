/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_typedefs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:37:09 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/28 15:25:24 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_TYPEDEFS_H
# define LFT_TYPEDEFS_H

/*
Think about using the enum in ft_printf
instead of the array of chars
*/

typedef long long int			t_ll;

typedef t_ll					t_llong;

typedef unsigned long long int	t_ull;

typedef t_ull					t_ullong;

typedef signed long long int	t_sllong;

typedef t_sllong				t_sll;

typedef unsigned char			t_uchar;

typedef const t_uchar			t_cuchar;

typedef signed int				t_sint;

typedef unsigned int			t_uint;

typedef const int				t_cint;

typedef const char				t_cchar;

typedef const size_t			t_csizet;

typedef const t_ll				t_cllong;

typedef const void				t_cvoid;

typedef void					(*t_pfunc)(t_pbuffer *, va_list *, char[128]);

typedef int						(*t_colorfunc)(t_cvoid *, t_cchar *, t_cint);

typedef void					(*t_delfunc)(void *);

typedef t_list					t_alloc;

typedef const t_list			t_clist;
#endif
