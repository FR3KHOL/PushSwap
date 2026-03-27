#include "push_swap.h"

static void	shift_down(t_list **stk)
{
	t_list	*curr;
	t_list	*last;

	last = ft_lstlast(*stk);
	curr = *stk;
	while (curr->next != NULL && curr->next != last)
		curr = curr->next;
	curr->next = NULL;
	last->next = *stk;
	*stk = last;
}

void	rra(t_list **stack_a)
{
	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	shift_down(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **stack_b)
{
	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	shift_down(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	shift_down(stack_a);
	shift_down(stack_b);
	ft_putstr_fd("rrr\n", 1);
}