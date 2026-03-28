#include "push_swap.h"

void	sort_pair(t_stack **stk_a)
{
	if ((*stk_a)->data > (*stk_a)->next->data)
	{
		swap_nodes(stk_a);
		write(1, "sa\n", 3);
	}
}

int	find_position(t_stack **stk, int target_idx)
{
	int		pos;
	t_stack	*curr;

	curr = *stk;
	pos = 0;
	while (curr != NULL && curr->index != target_idx)
	{
		curr = curr->next;
		pos++;
	}
	return (pos);
}

void	sort_trio(t_stack **stk_a)
{
	int	pos_of_max;

	pos_of_max = find_position(stk_a, 2);
	if (pos_of_max == 1)
	{
		rev_rotate_stack(stk_a);
		write(1, "rra\n", 4);
	}
	else if (pos_of_max == 0)
	{
		rotate_stack(stk_a);
		write(1, "ra\n", 3);
	}
	sort_pair(stk_a);
}

static void	shift_zero_to_top(t_stack **stk_a, int pos, int len)
{
	while (pos != len && pos > (len / 2))
	{
		rev_rotate_stack(stk_a);
		write(1, "rra\n", 4);
		pos++;
	}
	while (pos != 0 && pos <= (len / 2))
	{
		rotate_stack(stk_a);
		write(1, "ra\n", 3);
		pos--;
	}
}

void	sort_few(t_stack **stk_a, t_stack **stk_b, int len)
{
	if (len == 3)
	{
		sort_trio(stk_a);
		return ;
	}
	sort_pair(stk_a);
	shift_zero_to_top(stk_a, find_position(stk_a, 0), len);
	push_node(stk_b, stk_a);
	write(1, "pb\n", 3);
	assign_ranks(*stk_a);
	sort_few(stk_a, stk_b, len - 1);
	push_node(stk_a, stk_b);
	write(1, "pa\n", 3);
}