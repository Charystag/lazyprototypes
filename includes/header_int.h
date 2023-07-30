/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:35:12 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/30 11:17:20 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H
# define HEADER \
"/* ************************************************************************** */\n"\
"/*                                                                            */\n"\
"/*                                                        :::      ::::::::   */\n"\
"/*   test.h                                             :+:      :+:    :+:   */\n"\
"/*                                                    +:+ +:+         +:+     */\n"\
"/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */\n"\
"/*                                                +#+#+#+#+#+   +#+           */\n"\
"/*   Created: 2023/03/31 16:08:14 by nsainton          #+#    #+#             */\n"\
"/*   Updated: 2023/03/31 16:08:14 by nsainton         ###   ########.fr       */\n"\
"/*                                                                            */\n"\
"/* ************************************************************************** */\n\n"\

# define IND "#ifndef "
# define D "# define "
# define INC "# include "
# define END "#endif"
# define CBEG "/*"
# define CEND "*/"
# define INT "_int"
# include "libft.h"
# define BUFF_SIZE 100
# define MAX_LINE_LEN 75
# define MAX_FUNC_LINES 4
# define TABLEN 4
# define FILE_NAME_SIZE 1024
# define TMP_FILE "/tmp/tmp_header"
# define EXT ".c"
# define DEBUG_OUT 2
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
enum e_infos
{
	COMPLETE,
	INCOMPLETE,
	NO_FUNCTION
};

enum e_errors
{
	MEMORY = 10,
	COMMAND,
};

struct s_string_pointer
{
	char	**str;
	size_t	*size;
};

struct s_string
{
	char	*str;
	size_t	size;
};

struct s_descriptors
{
	int		dst;
	int		tmp;
	FILE	*src;
};

typedef struct s_descriptors	t_descriptors;

typedef const char				t_cchar;

typedef struct s_string_pointer	t_pstring;

typedef struct s_string			t_string;

typedef const int				t_cint;

#endif
