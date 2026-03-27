#include "push_swap.h"

static void	sort_3(t_list **a)
{
	t_list	*highest;

	if (a == NULL || *a == NULL)
		return ;
	highest = find_max(*a);
	if (*a == highest)
		ra(a);
	else if ((*a)->next == highest)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

static void	handle_five(t_list **stk_a, t_list **stk_b)
{
	int	len;

	len = ft_lstsize(*stk_a);
	while (len > 0)
	{
		if ((*stk_a)->index == 0 || (*stk_a)->index == 1)
			pb(stk_a, stk_b);
		else
			ra(stk_a);
		len--;
	}
	sort_3(stk_a);
	pa(stk_a, stk_b);
	pa(stk_a, stk_b);
	if ((*stk_a)->index > (*stk_a)->next->index)
		sa(stk_a);
}

static void	assign_indices(t_list *stk_a, int len)
{
	t_list	*max_node;
	t_list	*curr;

	if (stk_a == NULL)
		return ;
	while (len >= 0)
	{
		max_node = NULL;
		curr = stk_a;
		while (curr != NULL)
		{
			if (curr->index == 0 && (max_node == NULL
					|| curr->data > max_node->data))
				max_node = curr;
			curr = curr->next;
		}
		if (max_node != NULL)
			max_node->index = len;
		len--;
	}
}

static int	check_if_sorted(t_list *stk)
{
	if (stk == NULL)
		return (1);
	while (stk->next != NULL)
	{
		if (stk->data > stk->next->data)
			return (0);
		stk = stk->next;
	}
	return (1);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	if (check_if_sorted(*stack_a) == 0)
	{
		assign_indices(*stack_a, ft_lstsize(*stack_a) - 1);
		if (ft_lstsize(*stack_a) <= 3)
			sort_3(stack_a);
		else if (ft_lstsize(*stack_a) <= 5)
			handle_five(stack_a, stack_b);
		else
		{
			move_to_stack_b(stack_a, stack_b);
			move_largest_to_a(stack_a, stack_b);
		}
	}
}