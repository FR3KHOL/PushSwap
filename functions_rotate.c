#include "push_swap.h"

static void	shift_up(t_list **stk)
{
	t_list	*first;
	t_list	*last;

	first = *stk;
	last = ft_lstlast(*stk);
	*stk = (*stk)->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_list **stack_a)
{
	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	shift_up(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **stack_b)
{
	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	shift_up(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	shift_up(stack_a);
	shift_up(stack_b);
	ft_putstr_fd("rr\n", 1);
}