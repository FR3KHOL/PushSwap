#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stk_a;
	t_list	*stk_b;

	if (argc <= 2)
		return (0);
	if (check_args(argc, argv) == 0)
		print_error();
	stk_b = NULL;
	stk_a = fill_stack_a(argv);
	if (stk_a == NULL)
		print_error();
	sort(&stk_a, &stk_b);
	ft_lstclear(&stk_a);
	return (0);
}