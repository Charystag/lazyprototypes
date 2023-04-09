/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:35:12 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/04 15:42:03 by nsainton         ###   ########.fr       */
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
# define END "#endif"
# include "libft.h"
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
