#include "push_swap.h"

void	swap_nodes(t_stack **stk)
{
	t_stack	*first;
	t_stack	*second;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return ;
	first = *stk;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stk = second;
}

void	ss(t_stack **stk_a, t_stack **stk_b)
{
	swap_nodes(stk_a);
	swap_nodes(stk_b);
}

void	insert_top(t_stack **stk, t_stack *node)
{
	if (node == NULL)
		return ;
	node->next = *stk;
	*stk = node;
}

void	push_node(t_stack **dst, t_stack **src)
{
	t_stack	*top_src;

	if (src == NULL || *src == NULL)
		return ;
	top_src = *src;
	*src = (*src)->next;
	insert_top(dst, top_src);
}