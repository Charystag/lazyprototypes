/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:58:18 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/31 17:05:14 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUFF_SIZE 100
# define MAX_LINE_LEN 75
# define UTILITY "find "
# define OPT " -type f -name \\*.c"
# define MAX_FUNC_LINES 4
# define FILE_NAME_SIZE 1024
# define TMP_FILE "/tmp/tmp_header"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
# include "functions.h"
#endif
