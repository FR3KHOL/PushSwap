#include "push_swap.h"

static void	sort_3(t_list **a)
{
	t_list	*max;

	if (!*a || !a)
		return ;
	max = find_max(*a);
	if (*a == max)
		ra(a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

static void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	while (size > 0)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		size--;
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

static void	set_index(t_list *stack_a, int size)
{
	t_list	*biggest;
	t_list	*tmp;

	if (!stack_a)
		return ;
	while (size >= 0)
	{
		biggest = NULL;
		tmp = stack_a;
		while (tmp)
		{
			if (!tmp->index && (biggest == NULL
					|| tmp->data > biggest->data))
				biggest = tmp;
			tmp = tmp->next;
		}
		if (biggest)
			biggest->index = size;
		size--;
	}
}

static int	is_sorted(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	if (!is_sorted(*stack_a))
	{
		set_index(*stack_a, ft_lstsize(*stack_a) - 1);
		if (ft_lstsize(*stack_a) <= 3)
			sort_3(stack_a);
		else if (ft_lstsize(*stack_a) <= 5)
			sort_5(stack_a, stack_b);
		else
		{
			move_to_stack_b(stack_a, stack_b);
			move_largest_to_a(stack_a, stack_b);
		}
	}
}
