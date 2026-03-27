#include "push_swap.h"

static char	**join_all_args(char **av)
{
	char	**split_arr;
	char	*str_accum;
	char	*tmp_str;
	int		idx;

	idx = 2;
	if (av == NULL || *av == NULL)
		return (NULL);
	str_accum = ft_strdup(av[1]);
	if (str_accum == NULL)
		return (NULL);
	while (av[idx] != NULL)
	{
		tmp_str = ft_strjoin(str_accum, " ");
		if (tmp_str == NULL)
			return (free(str_accum), NULL);
		free(str_accum);
		str_accum = ft_strjoin(tmp_str, av[idx]);
		free(tmp_str);
		if (str_accum == NULL)
			return (NULL);
		idx++;
	}
	split_arr = ft_split(str_accum, ' ');
	return (free(str_accum), split_arr);
}

t_list	*fill_stack_a(char **argv)
{
	t_list	*new_node;
	t_list	*stk_a;
	char	**split_str;
	int		idx;

	split_str = join_all_args(argv);
	if (split_str == NULL || *split_str == NULL)
		return (NULL);
	stk_a = NULL;
	idx = 0;
	while (split_str[idx] != NULL)
	{
		new_node = ft_lstnew(ft_atoi(split_str[idx]));
		if (new_node == NULL)
		{
			ft_lstclear(&stk_a);
			return (NULL);
		}
		ft_lstadd_back(&stk_a, new_node);
		idx++;
	}
	return (stk_a);
}

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	free_args(char **args)
{
	int	idx;

	idx = 0;
	if (args == NULL)
		return ;
	while (args[idx] != NULL)
	{
		free(args[idx]);
		idx++;
	}
	free(args);
}