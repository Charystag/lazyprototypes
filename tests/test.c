/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:01:59 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/30 17:42:57 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonjour"
/*
	The norminette bot is saying Fuckyouinparticular to the function declared
	as `inline void` so I had to remove them from the included tests. However
	it allows me to show you that nested comments work well.
	The goal of this example file is to show you that no matter how you write
	your functions in your source code, they will look right and aligned in
	the header file you create with this header script. So you can only care
	about writting good code and not good looking code (even though good
	looking code is always appreciated)
*/

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

void	another_func(void *bonjour)
{
	/*code here*/
}

/*
inline void	test(extern int *b)
{
	/*code here*/
}
*/

struct s_no_name_idea   	func_test(struct s_i_dont_exist identifier)
{
	/* code here*/
}

extern int			test_function(extern int *b)
{
	/*code here*/
}

/*
inline void	*test(char (*f) (char *, int *, void *, unsigned int *), \
unsigned int *a)
{
	/*code here*/
}
*/

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

