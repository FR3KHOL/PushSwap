#include "push_swap.h"

static char	**prepare_args(char **argv)
{
	char	**list;
	char	*temp1;
	char	*temp2;
	int		i;

	i = 2;
	if (!*argv || !argv)
		return (NULL);
	temp1 = ft_strdup(argv[1]);
	if (!temp1)
		return (NULL);
	while (argv[i])
	{
		temp2 = ft_strjoin(temp1, " ");
		if (!temp2)
			return (free(temp1), NULL);
		free(temp1);
		temp1 = ft_strjoin(temp2, argv[i]);
		free(temp2);
		if (!temp1)
			return (NULL);
		i++;
	}
	list = ft_split(temp1, ' ');
	return (free(temp1), list);
}

t_list	*fill_stack_a(char **argv)
{
	t_list	*new;
	t_list	*stack_a;
	char	**list;
	int		i;

	list = prepare_args(argv);
	if (!list || !*list)
		return (NULL);
	stack_a = NULL;
	i = 0;
	while (list[i])
	{
		new = ft_lstnew(ft_atoi(list[i]));
		if (!new)
		{
			ft_lstclear(&stack_a);
			return (NULL);
		}
		ft_lstadd_back(&stack_a, new);
		i++;
	}
	return (stack_a);
}

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
