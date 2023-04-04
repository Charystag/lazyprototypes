/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:48:12 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/31 16:48:42 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "ft_types.h"

//Functions from file : /write_to_file.c

int		write_to_file(t_cchar *src_path, t_cint fd);

//Functions from file : /command_building.c

int		build_command(char **command, t_cchar *dirname);

int		getlist(FILE **list, t_cchar *path, char **filename, \
char **cpy);

//Functions from file : /destination.c

int		create_destination(t_cchar *destination_path, t_cchar *tmp_path, \
t_cint max);

//Functions from file : /writting.c

int		write_header_prot(t_cint fd, t_cchar *str);

//Functions from file : /checking.c

int		valid_path(t_cchar *path);

int		space_or_tab(int c);

size_t	tab_len(t_cchar *line);

//Functions from file : /func_checking.c

int		open_parenthesis(t_cchar *function);

int		is_func_prototype(t_cchar *line);

//Functions from file : /wrappers.c

ssize_t	getline_tstring(t_string *str, FILE *source);

//Functions from file : /cutting.c

void	cat_line_ret(char *new_line, t_cchar *line, size_t max);

#endif
