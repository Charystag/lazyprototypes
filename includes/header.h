/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:08:14 by nsainton          #+#    #+#             */
/*   Updated: 2023/05/08 15:53:31 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "header_int.h"

//Functions from file : checking.c
int		space_or_tab(int c);

size_t	tab_len(t_cchar *line);

void	comment_switch(const char *line, char *swit, size_t len);

//Functions from file : write_to_file.c
int		write_to_file(t_cchar *src_path, t_cint fd);

//Functions from file : wrappers.c
ssize_t	getline_tstring(t_string *str, FILE *source);

//Functions from file : destination.c
int		create_destination(t_cchar *destination_path, t_cchar *tmp_path, \
t_cint max);

//Functions from file : show_dir_contents.c
void	show_dir(char *path);

int		get_dir_entries(char *path, t_list **lst, char *ext);

//Functions from file : func_checking.c
int		open_parenthesis(t_cchar *function);

int		is_func_prototype(t_cchar *line);

//Functions from file : debug.c
void	print(void *string);

//Functions from file : writting.c
int		write_header_prot(t_cint fd, t_cchar *str);

//Functions from file : cutting.c
void	cat_line_ret(char *new_line, t_cchar *line, size_t max);

#endif
