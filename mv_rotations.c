#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp1;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp = *stack;
	temp1 = (*stack)->next;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = temp;
	(*stack)->next->next = NULL;
	*stack = temp1;
}

void	rr(t_stack **stack_to, t_stack **stack_from)
{
	rotate(stack_to);
	rotate(stack_from);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp1;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp = *stack;
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	temp1 = (*stack)->next;
	(*stack)->next = NULL;
	*stack = temp1;
	(*stack)->next = temp;
}

void	rrr(t_stack **stack_to, t_stack **stack_from)
{
	reverse_rotate(stack_to);
	reverse_rotate(stack_from);
}
