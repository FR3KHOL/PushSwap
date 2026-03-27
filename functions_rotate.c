#include "push_swap.h"

static void	ft_rotate_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;

	tmp = *stack;
	tail = ft_lstlast(*stack);
	*stack = (*stack)->next;
	tmp->next = NULL;
	tail->next = tmp;
}

void	ra(t_list **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	ft_rotate_rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	ft_rotate_rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	ft_rotate_rotate(stack_a);
	ft_rotate_rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
