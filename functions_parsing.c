#include "push_swap.h"

static int	has_no_duplicates(int val, char **args, int idx)
{
	idx++;
	while (args[idx] != NULL)
	{
		if (ft_atoi(args[idx]) == val)
			return (0);
		idx++;
	}
	return (1);
}

static char	*concatenate_args(int ac, char **av)
{
	char	*res;
	char	*tmp;
	int		idx;

	idx = 1;
	res = ft_strdup("");
	while (idx < ac)
	{
		if (av[idx][0] == '\0')
			return (free(res), NULL);
		tmp = ft_strjoin(res, " ");
		free(res);
		res = ft_strjoin(tmp, av[idx]);
		free(tmp);
		idx++;
	}
	return (res);
}

static int	is_valid_format(char *s)
{
	int	idx;

	idx = 0;
	if (!s || s[0] == '\0')
		return (0);
	while (s[idx] == ' ')
		idx++;
	if (s[idx] == '+' || s[idx] == '-')
		idx++;
	if (ft_isdigit(s[idx]) == 0)
		return (0);
	while (s[idx] != '\0')
	{
		if (ft_isdigit(s[idx]) == 0)
			return (0);
		idx++;
	}
	return (1);
}

static int	validate_elements(char **elements)
{
	long	val;
	int		idx;

	idx = 0;
	while (elements[idx] != NULL)
	{
		if (is_valid_format(elements[idx]) == 0 || elements[idx][0] == '\0')
			return (0);
		val = ft_atoi(elements[idx]);
		if (val > INT_MAX || val < INT_MIN)
			return (0);
		if (has_no_duplicates(val, elements, idx) == 0)
			return (0);
		idx++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	char	**split_args;

	if (argc < 2)
		return (0);
	split_args = ft_split(concatenate_args(argc, argv), ' ');
	if (split_args == NULL || split_args[0] == NULL)
		return (free_args(split_args), 0);
	if (validate_elements(split_args) == 0)
	{
		free_args(split_args);
		return (0);
	}
	free_args(split_args);
	return (1);
}