#include "push_swap.h"

static t_stack	*allocate_and_track(size_t size, t_gar **garb_head)
{
	t_stack	*new_node;
	t_gar	*old_garb;

	new_node = (t_stack *)malloc(size);
	if (new_node == NULL)
		return (NULL);
	old_garb = *garb_head;
	*garb_head = malloc(sizeof(t_gar));
	if (*garb_head == NULL)
		return (NULL);
	(*garb_head)->next = old_garb;
	(*garb_head)->ptr = new_node;
	return (new_node);
}

t_stack	*append_node(t_stack *stk, int val, t_gar **gc_head)
{
	t_stack	*item;

	item = allocate_and_track(sizeof(t_stack), gc_head);
	if (item == NULL)
		return (NULL);
	item->data = val;
	insert_top(&stk, item);
	rotate_stack(&stk);
	return (stk);
}

int	clear_garbage(t_gar *gc_list)
{
	t_gar	*current;

	current = gc_list;
	if (current == NULL)
		return (0);
	while (current != NULL)
	{
		free(current->ptr);
		current = current->next;
	}
	while (gc_list != NULL)
	{
		current = gc_list;
		gc_list = gc_list->next;
		free(current);
	}
	return (0);
}

int	has_duplicate(t_stack *stk, int val)
{
	while (stk != NULL)
	{
		if (stk->data == val)
			return (1);
		stk = stk->next;
	}
	return (0);
}

int	stack_length(t_stack *stk)
{
	int		len;
	t_stack	*curr;

	curr = stk;
	len = 0;
	while (curr != NULL)
	{
		curr = curr->next;
		len++;
	}
	return (len);
}