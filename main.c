#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc > 2)
	{
		if (!check_args(argc, argv))
			print_error();
		stack_a = fill_stack_a(argv);
		stack_b = NULL;
		if (!stack_a)
			print_error();
		sort(&stack_a, &stack_b);
		ft_lstclear(&stack_a);
	}
	return (0);
}
