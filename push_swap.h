#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
int		check_args(int ac, char **av);
void	print_error(void);
void	free_args(char **args);
t_list	*find_max(t_list *stack);
void	sort(t_list **a, t_list **b);
void	move_largest_to_a(t_list **stack_a, t_list **stack_b);
t_list	*fill_stack_a(char **list);
void	move_to_stack_b(t_list **stack_a, t_list **stack_b);

#endif
