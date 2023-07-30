/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:01:59 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/30 17:11:56 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonjour"

int	main(void)
{
	/*code here*/
}

static int	test(void)
{
	/*code here*/
}

int static	test(void)
{
	/*code here*/
}

int	test(void static a)
{
	/*code here*/
}

inline static int test(static void a)
{
	/*code here*/
}

inline void	test(extern int *b)
{
	/*code here*/
}

inline void	*test(char (*f) (char *, int *, void *, unsigned int *), \
unsigned int *a)
{
	/*code here*/
}

int	func_test(int a)
{
	/*code here*/
}

int	func_test2(int b)
{
	/*code here*/
}

/*

struct s_commented_function_type_but_way_too_long				func_test3(int a);
{
	//I am invisible lol
}

*//*

struct s_hidden_func		func_test7(int b);
{
	//Me too!
}

*/

int	func_test8(int c)
{
	/*code here*/
}

_Noreturn int	func_test9(int d)
{
	/*code here*/
}

int					func_test10(int a, static int c)
{
	/*code here*/
}

extern		unsigned 		int	func_test11(int a)
{
	/*code here*/
}

int			func_test12(int    a, static		void    *b)
{
	/*code here*/
}

int						        func_test13(int					a,						 static      void *b)
{
	/*code here*/
}

struct s_new_type	    	func_test14(unsigned int *a, uintptr_t (*func)(const char *a, \
unsigned int **b, const struct s_another_type boubou), int c)
{
	/*code here*/
}

struct s_very_very_long_and_annoying_type_name       	func_test15(unsigned int *a, int b)
{
	/*code here*/
}
