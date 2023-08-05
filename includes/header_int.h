/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:35:12 by nsainton          #+#    #+#             */
/*   Updated: 2023/08/05 09:08:18 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_INT_H
# define HEADER_INT_H
# define HEADER \
"/* ************************************************************************** */\n"\
"/*                                                                            */\n"\
"/*                                                        :::      ::::::::   */\n"\
"/*   lazyheader.h                                       :+:      :+:    :+:   */\n"\
"/*                                                    +:+ +:+         +:+     */\n"\
"/*   By: lazydev <lazydev@student.42.fr>            +#+  +:+       +#+        */\n"\
"/*                                                +#+#+#+#+#+   +#+           */\n"\
"/*   Created: 2023/03/31 16:08:14 by lazydev           #+#    #+#             */\n"\
"/*   Updated: 2023/03/31 16:08:14 by lazydev          ###   ########.fr       */\n"\
"/*                                                                            */\n"\
"/* ************************************************************************** */\n\n"\

# define IND "#ifndef "
# define D "# define "
# define INC "# include "
# define END "#endif"
# define CBEG "/*"
# define CEND "*/"
# define INT "_int"
# define BUFF_SIZE 100
# define MAX_LINE_LEN 79
# ifndef TABLEN
#  define TABLEN 4
# endif
# define PATH_SIZE 1024
# define TMP_FILE "/tmp/tmp_header"
# ifndef EXT
#  define EXT ".c"
# endif
# define PROG_NAME "header"
# define DEBUG_OUT 2
# define MIN(a,b) (((a) < (b)) ? (a) : (b))
# include <stdio.h>

struct s_list
{
	void			*content;
	struct s_list	*next;
};

struct s_str
{
	char	*str;
	size_t	len;
	size_t	size;
};


#endif
