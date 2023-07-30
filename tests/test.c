/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:01:59 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/28 16:22:09 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonjour"

int	main(void);

static int	test(void);

int static	test(void);

int	test(static void);

inline static int test(void);

inline void	test(static void);

inline void	*test(static void);

int	func_test(int a);

int	func_test2(int b);

/*

int				func_test3(int a);

*//*

int		func_test7(int b);

*/

int	func_test8(int c);

_Noreturn int	func_test9(int d);

int					func_test10(int a, static int c);

extern		unsigned 		int	func_test11(int a);

