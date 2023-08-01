/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:08:14 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/31 16:08:14 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "header_int.h"
//Functions from file : format_prototype.c
char			*format_prototype(const char *prototype, \
const unsigned int max_distance, unsigned int *prototype_len);

//Functions from file : write_prototypes.c
int				write_prototypes(const char *source_file, \
const char *destination_file, const unsigned int max_distance, \
char **includes);

//Functions from file : get_codeline.c
int				get_codeline(struct s_str **buff, FILE *fstream);

//Functions from file : format_header.c
int				header_header(const char *header, char **includes);

//Functions from file : get_prototypes.c
int				get_prototypes_file(const char *filename, int tmp_fd, \
unsigned int *max_distance);

char			*get_filename(char *content);

unsigned int	get_prototypes(t_list **filenames, const char *tmp_file, \
unsigned int *max_distance);

//Functions from file : get_dir_entries.c
int				get_dir_entries(const char *path, struct s_list **lst, \
const char *ext);

//Functions from file : main.c
//Functions from file : func_checking.c
int				open_parenthesis(t_cchar *function);

unsigned int	compute_distance(t_cchar *line, \
const unsigned int end_of_types);

unsigned int	is_func_prototype(t_cchar *line);

//Functions from file : checking.c
int				space_or_tab(int c);

size_t			tabslen(t_cchar *line);

size_t			tabsnlen(t_cchar *line, const size_t n);

int				comment_switch(const char *line, int *swit, size_t len);

#endif