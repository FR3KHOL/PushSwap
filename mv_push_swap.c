#include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*temp;
	t_stack	*temp1;

	if (!(*head) || !((*head)->next))
		return ;
	temp = *head;
	*head = (*head)->next;
	temp1 = (*head)->next;
	(*head)->next = temp;
	(*head)->next->next = temp1;
	return ;
}

void	ss(t_stack **head1, t_stack **head2)
{
	swap(head1);
	swap(head2);
}

void	push(t_stack **stack, t_stack *element)
{
	t_stack	*temp;

	if (!element)
		return ;
	temp = *stack;
	*stack = element;
	(*stack)->next = temp;
}

void	p(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*temp;

	if (!(*stack_from))
		return ;
	temp = *stack_from;
	*stack_from = (*stack_from)->next;
	push(stack_to, temp);
}
