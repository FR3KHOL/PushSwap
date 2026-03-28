#include "push_swap.h"

static void	execute_sorting_strategy(t_stack **stk_a, t_stack **stk_b, int len)
{
	if (is_sorted(*stk_a) == 1)
		return ;
	if (len == 2)
		sort_pair(stk_a);
	else
	{
		assign_ranks(*stk_a);
		if (len == 3)
			sort_trio(stk_a);
		else if (len >= 4 && len <= 15)
			sort_few(stk_a, stk_b, len);
		else
		{
			distribute_elements(stk_a, stk_b);
			pull_back_to_a(stk_a, stk_b, stack_length(*stk_b));
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_gar	*gc_head;

	if (argc < 2)
		return (0);
	stk_a = NULL;
	stk_b = NULL;
	gc_head = NULL;
	if (parse_arguments(&stk_a, argc, argv, &gc_head) == 0)
	{
		clear_garbage(gc_head);
		write(2, "Error\n", 6);
		return (0);
	}
	execute_sorting_strategy(&stk_a, &stk_b, stack_length(stk_a));
	clear_garbage(gc_head);
	return (0);
}