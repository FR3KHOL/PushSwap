#include "push_swap.h"

static t_stack	*fetch_last_node(t_stack *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	rotate_stack(t_stack **stk)
{
	t_stack	*first;
	t_stack	*last;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return ;
	first = *stk;
	last = fetch_last_node(*stk);
	*stk = first->next;
	first->next = NULL;
	last->next = first;
}

void	rr(t_stack **stk_a, t_stack **stk_b)
{
	rotate_stack(stk_a);
	rotate_stack(stk_b);
}

void	rev_rotate_stack(t_stack **stk)
{
	t_stack	*prev;
	t_stack	*last;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return ;
	prev = *stk;
	while (prev->next->next != NULL)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stk;
	*stk = last;
}

void	rrr(t_stack **stk_a, t_stack **stk_b)
{
	rev_rotate_stack(stk_a);
	rev_rotate_stack(stk_b);
}