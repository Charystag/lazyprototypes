/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_functions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 06:26:12 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/28 16:34:24 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_FUNCTIONS_H
# define LFT_FUNCTIONS_H
# include "lft_librairies.h"
# include "lft_structures.h"
# include "lft_enums.h"
# include "lft_typedefs.h"

/*
Don't forget to declare to const what needs to
be declared as const
*/

//Functions from address.c [       2 functions]

void		put_address(t_pbuffer *buf, va_list *ap, char flags[128]);

//Functions from allocation.c [       2 functions]

void		*ft_calloc(size_t nmemb, size_t size);

void		*ft_realloc(void *memzone, size_t old_size, size_t new_size);

//Functions from ascii1.c [       5 functions]

int			ft_isalnum(int c);

int			ft_isascii(int c);

int			ft_isdigit(int c);

int			ft_isprint(int c);

int			ft_isspace(int c);

//Functions from ascii2.c [       5 functions]

int			ft_isupper(int c);

int			ft_islower(int c);

int			ft_isalpha(int c);

int			ft_tolower(int c);

int			ft_toupper(int c);

//Functions from base.c [	1 functions]

int			ft_atoi_base(t_cchar *s, t_cchar *base, t_csizet base_len);

//Functions from colors_print.c [	4 functions]

int			print_color_string(t_cvoid *s, t_cchar *color, t_cint fd);

int			print_color_number(t_cvoid *nb, t_cchar *color, t_cint fd);

t_colorfunc	chose_function(t_cint type);

int			print_color(t_cvoid *s, t_cint type, t_cchar *color, t_cint fd);

int			print_colors(t_cvoid **s, t_cint *type, \
t_cchar **colors, t_cint *infos);

//Functions from count_equal.c [	1 functions]

t_llong		findlongestsubstr(t_cchar *haystack, t_cchar *needle);

//Functions from decimal.c [       3 functions]

void		put_pos(t_ull nb, char **tab, char *base);

void		put_dec(t_pbuffer *buf, va_list *ap, char flags[128]);

void		put_unsigned(t_pbuffer *buf, va_list *ap, char flags[128]);

//Functions from flush.c [       3 functions]

void		flush(t_pbuffer *buf);

void		flush_fd(t_pbuffer *buf);

void		flush_str(t_pbuffer *buf);

//Functions from ft_atoi.c [       1 functions]

int			ft_atoi(t_cchar *nptr);

//Functions from ft_bzero.c [       1 functions]

void		ft_bzero(void *s, size_t n);

//Functions from ft_itoa.c [       3 functions]

char		*ft_itoa(int n);

//Functions from ft_printf.c [       3 functions]

int			ft_printf(t_cchar *format, ...);

int			ft_dprintf(int fd, t_cchar *format, ...);

int			ft_vdprintf(int fd, t_cchar *format, va_list ap);

//Functions from ft_split.c [       4 functions]

char		**ft_split(t_cchar*s, char c);

//Functions from ft_sprintf.c [       3 functions]

int			ft_snprintf(char *str, size_t size, t_cchar *format, ...);

int			ft_sprintf(t_str *str, t_cchar *format, ...);

int			ft_vsnprintf(t_str *str, t_cchar *format, va_list ap);

//Functions from ft_strchr.c [       1 functions]

char		*ft_strchr(t_cchar *s, int c);

//Functions from ft_strdup.c [       1 functions]

char		*ft_strdup(t_cchar *s);

//Functions from ft_striteri.c [       1 functions]

void		ft_striteri(char *s, void (*f) (unsigned int, char *));

//Functions from ft_strjoin.c [       1 functions]

char		*ft_strjoin(t_cchar*s1, t_cchar*s2);

//Functions from ft_strlcat.c [       1 functions]

size_t		ft_strlcat(char *dst, t_cchar *src, size_t size);

//Functions from ft_strlcpy.c [       1 functions]

size_t		ft_strlcpy(char *dst, t_cchar *src, size_t size);

//Functions from ft_strmapi.c [       1 functions]

char		*ft_strmapi(t_cchar *s, char (*f) (unsigned int, char));

//Functions from ft_strncat.c [       1 functions]

size_t		ft_strncat(char *dest, t_cchar *src, size_t n);

//Functions from ft_strncmp.c [       1 functions]

int			ft_strncmp(t_cchar *s1, t_cchar *s2, size_t n);

int			ft_strcmp(t_cchar *s1, t_cchar *s2);

int			cmp_until(t_cchar *s1, t_cchar *s2, t_cchar c);

//Functions from ft_strnstr.c [       2 functions]

char		*ft_strnstr(t_cchar *s1, t_cchar *s2, size_t n);

//Functions from ft_strrchr.c [       1 functions]

char		*ft_strrchr(t_cchar *s, int c);

//Functions from ft_strtrim.c [       2 functions]

char		*ft_strtrim(t_cchar *s1, t_cchar *set);

//Functions from ft_substr.c [       2 functions]

char		*ft_substr(t_cchar*s, unsigned int start, size_t len);

//Functions from get_next_line.c [       5 functions]

int			parse_line(t_gline *line, \
char buf[BUFFER_SIZE + 1], t_csizet bytes);

int			fill_line(t_gline *line, char buf[BUFFER_SIZE + 1]);

int			ft_check_line(char buf[BUFFER_SIZE + 1], char *line, \
ssize_t n_read);

char		*get_next_line(int fd);

//Functions from helpers.c [       5 functions]

int			max_int(int a, int b);

int			min_int(int a, int b);

t_ull		abs_ll(t_ll a);

t_ull		itou(int n);

t_ull		lltoull(t_ll n);

//Functions from hexadecimal.c [       5 functions]

void		put_hex_min(t_pbuffer *buf, va_list *ap, char flags[128]);

void		put_hex_maj(t_pbuffer *buf, va_list *ap, char flags[128]);

//Functions from init.c [       5 functions]

void		init_pbuf_fd(t_pbuffer *buf, int fd);

void		init_pbuf_str(t_pbuffer *buf, t_str *str);

void		set_pad(char flags[128], t_print *pads);

t_pfunc		*get_funcs(void);

//Functions from lst_access.c [			4 functions]

void		setnext(t_list *node, t_list *next);

t_list		*getnext(t_clist *node);

void		setcontent(t_list *node, void *content);

void		*getcontent(t_clist *node);

//Functions from lst_addelem.c [       3 functions]

t_list		*ft_lstnew(void *content);

t_list		*ft_lstnew_cpy(t_cvoid *content, size_t size);

void		ft_lstadd_front(t_list **lst, t_list *new);

void		ft_lstadd_back(t_list **lst, t_list *new);

//Functions from lst_delelem.c [       2 functions]

void		ft_lstdelone(t_list *lst, void (*del) (void *));

void		ft_lstclear(t_list **lst, void (*del) (void *));

void		ft_lstdel_front(t_list **lst, void (*del) (void *));

//Functions from lst_functions.c [       5 functions]

int			ft_lstsize(t_clist *lst);

t_list		*ft_lstlast(t_clist *lst);

void		ft_lstiter(t_list *lst, void (*f) (void *));

t_list		*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *));

//Functions from memfuncs.c [       5 functions]

void		*ft_memchr(t_cvoid *s, int c, size_t n);

int			ft_memcmp(t_cvoid *s1, t_cvoid *s2, size_t n);

void		*ft_memcpy(void *dest, t_cvoid *src, size_t n);

void		*ft_memmove(void *dest, t_cvoid *src, size_t n);

void		*ft_memset(void *b, int c, size_t len);

//Functions from minimum.c [       3 functions]

t_sint		ft_minint(t_sint a, t_sint b);

t_uint		ft_minuint(t_uint a, t_uint b);

size_t		ft_minst(size_t a, size_t b);

//Functions from parsing.c [       2 functions]

void		parse_conv(int *width, int *prec, t_cchar **conv, \
char flags[128]);

void		loop(t_pbuffer *buf, t_cchar **conv);

//Functions from pbuffer.c [       4 functions]

void		add_char(t_pbuffer *buf, char c);

void		add_nchar(t_pbuffer *buf, char c, int n);

void		add_str(t_pbuffer *buf, char *str);

void		add_nstr(t_pbuffer *buf, char *str, int n);

void		add_conv(t_cchar **s, t_pbuffer *buf, va_list *ap, char flags[128]);

//Functions from percent.c [       1 functions]

void		put_percent(t_pbuffer *buf, va_list *ap, char flags[128]);

//Functions from print_fd.c [       4 functions]

int			ft_putchar_fd(t_cchar c, t_cint fd);

int			ft_putstr_fd(t_cchar *s, t_cint fd);

int			ft_putendl_fd(t_cchar *s, t_cint fd);

int			ft_putnbr_fd(t_cint n, t_cint fd);

//Functions from printing.c [       2 functions]

void		build_res(t_pbuffer *buf, char *res, char flags[128], int len);

void		print_res(t_pbuffer *buf, char *res, int len, t_print *pads);

//Functions from putnbr_tab.c [       2 functions]

void		put_uns_tab(t_ull nb, char **tab, char *base, size_t len);

void		put_nb_tab(t_ll nb, char *tab, char *base);

//Functions from strings.c [       3 functions]

void		put_char(t_pbuffer *buf, va_list *ap, char flags[128]);

void		put_string(t_pbuffer *buf, va_list *ap, char flags[128]);

//Functions from strlength.c [       2 functions]

size_t		ft_strlen(t_cchar *s);

size_t		ft_strnlen(t_cchar *s, t_csizet maxlen);

//Functions from tstr_add.c [       2 functions]

int			tstr_addchar(t_str *str, char c);

size_t		tstrncat(t_str *str, t_cchar *s, size_t bytes);

//Functions from tstr_alloc.c [		1 functions]

t_str		*tstr_realloc(t_str *old_string, size_t new_size);

//Functions from tstr_del.c [       1 functions]

void		tstr_del(t_str *str);

//Functions from tstr_init.c [       3 functions]

void		tstr_init(t_str *str);

int			tstr_initstr(t_str *tstr, char *str, size_t buffsize);

int			tstr_cpy(t_str *dst, const t_str *src);

//Functions from tstr_print.c [       2 functions]

void		tstr_print(t_str *str);

void		tstr_print_fd(t_str *str, int fd);

#endif
