#include "push_swap.h"

static int	check_descending(t_list *node, int limit)
{
	int	streak;

	streak = 0;
	while (node != NULL && node->next != NULL)
	{
		if (node->data >= node->next->data)
			streak++;
		else
			streak = 0;
		if (streak >= limit)
			return (1);
		node = node->next;
	}
	return (0);
}

static void	execute_rotation(t_list **stk_a, int limit)
{
	if (check_descending(*stk_a, limit) == 1)
		rra(stk_a);
	else
		ra(stk_a);
}

void	move_to_stack_b(t_list **stack_a, t_list **stack_b)
{
	int	chunk_size;
	int	pushed_count;

	pushed_count = 0;
	if (ft_lstsize(*stack_a) > 100)
		chunk_size = 30;
	else
		chunk_size = 15;
	while (ft_lstsize(*stack_a) > 0)
	{
		if ((*stack_a)->index <= pushed_count)
		{
			pb(stack_a, stack_b);
			pushed_count++;
		}
		else if ((*stack_a)->index <= (pushed_count + chunk_size))
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			pushed_count++;
		}
		else
			execute_rotation(stack_a, ft_lstsize(*stack_a) / 4);
	}
}