/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_librairies.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 08:01:59 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/11 01:55:50 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_LIBRAIRIES_H
# define LFT_LIBRAIRIES_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <sys/types.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# ifdef FILES
#  undef FILES
# endif
# define FILES 123
# ifdef PBUFFER_SIZE
#  undef PBUFFER_SIZE
# endif
# define PBUFFER_SIZE 1000
# define DEC "0123456789"
# define HEX "0123456789abcdef"
# define HEX_MAJ "0123456789ABCDEF"
# define FLAGS "# +-0"
# define SPECIFIERS "cspdiuxX%"
# define P_CONV "cspdiuxX"
# define ADMITTED "c;s;p;d;i;u;x;X;%;"
# define SEPARATOR ';'
#endif
