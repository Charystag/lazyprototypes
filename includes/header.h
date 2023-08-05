/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lazyheader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazydev <lazydev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:08:14 by lazydev           #+#    #+#             */
/*   Updated: 2023/03/31 16:08:14 by lazydev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "header_int.h"
# include "header42.h"
//Functions from file : string_object.c
size_t			tstrncat(struct s_str *str, const char *s, size_t bytes);

struct s_str	*tstr_realloc(struct s_str *old_string, size_t new_size);

void			tstr_reinit(struct s_str *str);

int				tstr_init(struct s_str *str, size_t size);

void			tstr_del(struct s_str *str);

//Functions from file : utils.c
char			*ft_strnstr(const char *s1, const char *s2, size_t n);

char			*ft_strmapi(char const *s, int (*f) (unsigned int, int));

size_t			ft_strcat(char *dest, const char *src);

//Functions from file : func_checking.c
int				open_parenthesis(const char *function);

unsigned int	compute_distance(const char *line, \
const unsigned int end_of_types);

unsigned int	is_func_prototype(const char *line);

//Functions from file : linked_list.c
struct s_list	*ft_lstnew_cpy(const void *content, size_t size);

void			ft_lstadd_front(struct s_list **lst, struct s_list *new);

void			ft_lstclear(struct s_list **lst, void (*del) (void *));

void			ft_lstdel_front(struct s_list **lst, void (*del) (void *));

//Functions from file : dynamic_header.c
int				dynamic_header(const char *header_name, \
const char *script_path);

//Functions from file : get_codeline.c
int				get_codeline(struct s_str **buff, FILE *fstream);

//Functions from file : get_dir_entries.c
int				get_dir_entries(const char *path, struct s_list **lst, \
const char *ext);

//Functions from file : format_header.c
int				header_header(const char *header, char **includes);

//Functions from file : format_prototype.c
char			*format_prototype(const char *prototype, \
const unsigned int max_distance, unsigned int *prototype_len);

//Functions from file : checking.c
int				space_or_tab(int c);

size_t			tabslen(const char *line);

size_t			tabsnlen(const char *line, const size_t n);

int				comment_switch(const char *line, int *swit, size_t len);

//Functions from file : write_prototypes.c
int				write_prototypes(const char *source_file, \
const char *destination_file, const unsigned int max_distance, \
char **includes);

//Functions from file : main.c
//Functions from file : get_prototypes.c
int				get_prototypes_file(const char *filename, int tmp_fd, \
unsigned int *max_distance);

char			*get_filename(char *content);

unsigned int	get_prototypes(struct s_list **filenames, const char *tmp_file, \
unsigned int *max_distance);

#endif