#include "push_swap.h"

int	is_sorted(t_stack *stk)
{
	while (stk != NULL && stk->next != NULL)
	{
		if (stk->next->data < stk->data)
			return (0);
		stk = stk->next;
	}
	return (1);
}

static int	count_smaller_items(t_stack *stk, int ref_val)
{
	int		count;
	t_stack	*curr;

	count = 0;
	curr = stk;
	while (curr != NULL)
	{
		if (curr->data < ref_val)
			count++;
		curr = curr->next;
	}
	return (count);
}

void	assign_ranks(t_stack *stk)
{
	t_stack	*curr;

	curr = stk;
	while (curr != NULL)
	{
		curr->index = count_smaller_items(stk, curr->data);
		curr = curr->next;
	}
}

void	distribute_elements(t_stack **stk_a, t_stack **stk_b)
{
	int	len;
	int	pushed;
	int	chunk_limit;

	len = stack_length(*stk_a);
	chunk_limit = (len / 20) + 7;
	pushed = 0;
	while (*stk_a != NULL)
	{
		if ((*stk_a)->index > pushed + chunk_limit)
		{
			rotate_stack(stk_a);
			write(1, "ra\n", 3);
		}
		else if ((*stk_a)->index <= (pushed + chunk_limit))
		{
			push_node(stk_b, stk_a);
			write(1, "pb\n", 3);
			if ((*stk_b)->index <= pushed)
			{
				rotate_stack(stk_b);
				write(1, "rb\n", 3);
			}
			pushed++;
		}
	}
}

void	pull_back_to_a(t_stack **stk_a, t_stack **stk_b, int len)
{
	int	idx;

	if (*stk_b == NULL)
		return ;
	idx = find_position(stk_b, len - 1);
	while (idx != len && idx > (len / 2))
	{
		rev_rotate_stack(stk_b);
		write(1, "rrb\n", 4);
		idx++;
	}
	while (idx != 0 && idx <= (len / 2))
	{
		rotate_stack(stk_b);
		write(1, "rb\n", 3);
		idx--;
	}
	push_node(stk_a, stk_b);
	write(1, "pa\n", 3);
	assign_ranks(*stk_a);
	pull_back_to_a(stk_a, stk_b, len - 1);
}