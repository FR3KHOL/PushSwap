#include "push_swap.h"

static int	is_duplicate(int num, char **argv, int position)
{
	position++;
	while (argv[position])
	{
		if (ft_atoi(argv[position]) == num)
			return (0);
		position++;
	}
	return (1);
}

static char	*args_to_str(int argc, char **argv)
{
	char	*str;
	char	*temp;
	int		i;

	i = 1;
	str = ft_strdup("");
	while (i < argc)
	{
		if (!argv[i][0])
			return (free(str), NULL);
		temp = ft_strjoin(str, " ");
		free(str);
		str = ft_strjoin(temp, argv[i]);
		free(temp);
		i++;
	}
	return (str);
}

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	args_valid(char **args)
{
	long	tmp;
	int		i;

	i = 0;
	while (args[i])
	{
		if (!is_number(args[i]) || !args[i][0])
			return (0);
		tmp = ft_atoi(args[i]);
		if (tmp < INT_MIN || tmp > INT_MAX || !is_duplicate(tmp, args, i))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	char	**args;

	if (argc < 2)
		return (0);
	args = ft_split(args_to_str(argc, argv), ' ');
	if (!args || !args[0] || !args_valid(args))
		return (free_args(args), 0);
	free_args(args);
	return (1);
}
