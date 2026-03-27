#include "push_swap.h"

static void	ft_rev_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;

	tail = ft_lstlast(*stack);
	tmp = *stack;
	while (tmp->next != tail && tmp->next)
		tmp = tmp->next;
	tmp->next = NULL;
	tail->next = *stack;
	*stack = tail;
}

void	rra(t_list **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	ft_rev_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	ft_rev_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
