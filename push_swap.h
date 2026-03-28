#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_stack
{
	struct t_stack	*next;
	int				index;
	int				data;
}					t_stack;

typedef struct t_gar
{
	struct t_gar	*next;
	void			*ptr;
}					t_gar;

/* parse_input.c */
int		parse_arguments(t_stack **stk, int argc, char **argv, t_gar **gc);

/* stack_utils.c */
t_stack	*append_node(t_stack *stk, int val, t_gar **gc_head);
int		clear_garbage(t_gar *gc_list);
int		has_duplicate(t_stack *stk, int val);
int		stack_length(t_stack *stk);

/* ops_push_swap.c */
void	swap_nodes(t_stack **stk);
void	ss(t_stack **stk_a, t_stack **stk_b);
void	insert_top(t_stack **stk, t_stack *node);
void	push_node(t_stack **dst, t_stack **src);

/* ops_rotate.c */
void	rotate_stack(t_stack **stk);
void	rr(t_stack **stk_a, t_stack **stk_b);
void	rev_rotate_stack(t_stack **stk);
void	rrr(t_stack **stk_a, t_stack **stk_b);

/* algo_chunk.c */
int		is_sorted(t_stack *stk);
void	assign_ranks(t_stack *stk);
void	distribute_elements(t_stack **stk_a, t_stack **stk_b);
void	pull_back_to_a(t_stack **stk_a, t_stack **stk_b, int len);

/* sort_small.c */
void	sort_pair(t_stack **stk_a);
int		find_position(t_stack **stk, int target_idx);
void	sort_trio(t_stack **stk_a);
void	sort_few(t_stack **stk_a, t_stack **stk_b, int len);

#endif