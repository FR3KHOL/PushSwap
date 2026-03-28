#include "push_swap.h"

static void	decide_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (check_sort(*stack_a))
		return ;
	else if (size == 2)
		sort_two(stack_a);
	else
	{
		indexer(*stack_a);
		if (size == 3)
			sort_three(stack_a);
		else if (size >= 4 && size <= 15)
			sort_small(stack_a, stack_b, size);
		else
		{
			k_distrub(stack_a, stack_b);
			push_back(stack_a, stack_b, l_size(*stack_b));
		}
	}
	return ;
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_gar	*garbage;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	garbage = NULL;
	if (parse_av(&stack_a, ac, av, &garbage) == 0)
	{
		free_gc(garbage);
		return (write(2, "Error\n", 6));
	}
	decide_sort(&stack_a, &stack_b, l_size(stack_a));
	free_gc(garbage);
}
