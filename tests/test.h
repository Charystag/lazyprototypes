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

#ifndef TEST_H
# define TEST_H
//Functions from file : test.c
int												test(void static a);

void											another_func(void *bonjour);

struct s_no_name_idea							\
func_test(struct s_i_dont_exist identifier);

extern int										\
test_function(extern int *b);

int												func_test(int a);

int												func_test2(int b);

int												func_test8(int c);

_Noreturn int									func_test9(int d);

int												func_test10(int a, \
static int c);

extern unsigned int								func_test11(int a);

int												func_test12(int a, \
static void *b);

int												func_test13(int a, \
static void *b);

struct s_new_type								func_test14(unsigned int *a, \
uintptr_t (*func)(const char *a, unsigned int **b, \
const struct s_another_type boubou), int c);

struct s_very_very_long_and_annoying_type_name	func_test15(unsigned int *a, \
int b);

struct s_splitted_func_prototype				func_test16(unsigned int *a, \
struct s_type b, struct s_another_var c, );

struct s_wandering_prototype					func_test17(int a, \
unsigned int b);

struct s_freely_formatted_func					func_test18(int a, \
const char *b);

#endif