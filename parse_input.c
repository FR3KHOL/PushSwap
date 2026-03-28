#include "push_swap.h"

static int	is_numeric(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static char	*ignore_spaces(const char *s)
{
	while (*s == ' ')
		s++;
	return ((char *)s);
}

static char	*check_and_skip_sign(const char *str, int *sign_val)
{
	str = ignore_spaces(str);
	if ((*str == '+' || *str == '-') && is_numeric(*(str + 1)))
	{
		if (*str == '-')
			*sign_val *= -1;
		str++;
	}
	return ((char *)str);
}

static long	custom_atoi_err(const char **str_ptr)
{
	int		multiplier;
	long	result;

	multiplier = 1;
	*str_ptr = check_and_skip_sign(*str_ptr, &multiplier);
	result = 0;
	if (is_numeric(**str_ptr) == 0 && **str_ptr != '\0')
		return ((long)INT_MAX + 1);
	while (is_numeric(**str_ptr))
	{
		result = (result * 10) + (**str_ptr - '0');
		if ((result > (long)INT_MAX && multiplier == 1)
			|| result > (long)INT_MAX + 1)
			return ((long)INT_MAX + 1);
		(*str_ptr)++;
	}
	if (**str_ptr != ' ' && **str_ptr != '\0')
		return ((long)INT_MAX + 1);
	return (result * multiplier);
}

int	parse_arguments(t_stack **stk, int argc, char **argv, t_gar **gc)
{
	int		idx;
	long	val;

	idx = 1;
	while (idx < argc)
	{
		if (*argv[idx] == '\0' || *ignore_spaces(argv[idx]) == '\0')
			return (0);
		while (*argv[idx] != '\0')
		{
			val = custom_atoi_err((const char **)&argv[idx]);
			if (val == (long)INT_MAX + 1)
				return (0);
			if (*argv[idx] == '\0' && val == 0 && *(argv[idx] - 1) == ' ')
				break ;
			if (has_duplicate(*stk, (int)val) == 1)
				return (0);
			*stk = append_node(*stk, (int)val, gc);
			if (*stk == NULL)
				return (0);
		}
		idx++;
	}
	return (1);
}