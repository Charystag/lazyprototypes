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
