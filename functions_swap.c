#include "push_swap.h"

static void	swap_top_nodes(t_list **stk)
{
	t_list	*first;
	t_list	*next_node;

	first = *stk;
	next_node = (*stk)->next;
	first->next = next_node->next;
	next_node->next = first;
	*stk = next_node;
}

void	sa(t_list **stack)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	swap_top_nodes(stack);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **stack)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	swap_top_nodes(stack);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	swap_top_nodes(stack_a);
	swap_top_nodes(stack_b);
	ft_putstr_fd("ss\n", 1);
}