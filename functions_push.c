#include "push_swap.h"

static void	move_node_top(t_list **src, t_list **dst)
{
	t_list	*first_src;

	first_src = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = first_src;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	if (stack_b == NULL || *stack_b == NULL)
		return ;
	move_node_top(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || *stack_a == NULL)
		return ;
	move_node_top(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}