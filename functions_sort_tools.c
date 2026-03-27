#include "push_swap.h"

t_list	*find_max(t_list *stack)
{
	t_list	*max_node;

	max_node = stack;
	while (stack)
	{
		if (stack->data > max_node->data)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

static int	get_position(t_list *stack, t_list *target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == target)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

void	move_largest_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*largest;
	int		size;
	int		pos;

	while (*stack_b)
	{
		largest = find_max(*stack_b);
		size = ft_lstsize(*stack_b);
		pos = get_position(*stack_b, largest);
		while (*stack_b != largest)
		{
			if (pos < (size / 2))
				rb(stack_b);
			else
				rrb(stack_b);
			pos = get_position(*stack_b, largest);
		}
		pa(stack_a, stack_b);
	}
}
