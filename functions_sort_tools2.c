#include "push_swap.h"

static int	is_decreasing(t_list *a, int half)
{
	int	count;

	count = 0;
	while (a && a->next)
	{
		if (a->data >= a->next->data)
			count++;
		else
			count = 0;
		if (count >= half)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	do_move(t_list **stack_a, int half)
{
	if (is_decreasing(*stack_a, half))
		rra(stack_a);
	else
		ra(stack_a);
}

void	move_to_stack_b(t_list **stack_a, t_list **stack_b)
{
	int	range;
	int	i;

	i = 0;
	if (ft_lstsize(*stack_a) > 100)
		range = 30;
	else
		range = 15;
	while (ft_lstsize(*stack_a))
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= (i + range))
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else
			do_move(stack_a, ft_lstsize(*stack_a) / 4);
	}
}
