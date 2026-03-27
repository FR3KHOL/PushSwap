#include "push_swap.h"

static void	ft_swap_stack(t_list **stack)
{
	t_list	*top;
	t_list	*second;

	top = *stack;
	second = (*stack)->next;
	top->next = second->next;
	second->next = top;
	*stack = second;
}

void	sa(t_list **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return ;
	ft_swap_stack(stack);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return ;
	ft_swap_stack(stack);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	ft_swap_stack(stack_a);
	ft_swap_stack(stack_b);
	ft_putstr_fd("ss\n", 1);
}
