#include "push_swap.h"

t_list	*find_max(t_list *stack)
{
	t_list	*highest;

	highest = stack;
	while (stack != NULL)
	{
		if (stack->data > highest->data)
			highest = stack;
		stack = stack->next;
	}
	return (highest);
}

static int	fetch_node_index(t_list *stk, t_list *node_to_find)
{
	int	idx;

	idx = 0;
	while (stk != NULL)
	{
		if (stk == node_to_find)
			return (idx);
		idx++;
		stk = stk->next;
	}
	return (-1);
}

void	move_largest_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*biggest;
	int		len;
	int		idx;

	while (*stack_b != NULL)
	{
		biggest = find_max(*stack_b);
		len = ft_lstsize(*stack_b);
		idx = fetch_node_index(*stack_b, biggest);
		while (*stack_b != biggest)
		{
			if (idx < (len / 2))
				rb(stack_b);
			else
				rrb(stack_b);
			idx = fetch_node_index(*stack_b, biggest);
		}
		pa(stack_a, stack_b);
	}
}