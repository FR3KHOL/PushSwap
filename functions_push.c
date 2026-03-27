#include "push_swap.h"

static void	push_stack(t_list **stack1, t_list **stack2)
{
	t_list	*top;

	top = (*stack1)->next;
	(*stack1)->next = *stack2;
	*stack2 = *stack1;
	*stack1 = top;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_b || !stack_b)
		return ;
	push_stack(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a || !stack_a)
		return ;
	push_stack(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
