#include "../includes/push_swap.h"

int	parse_int(int *num, char *str)
{
	if (is_int(str))
	{
		*num = ft_atoi(str);
		return (1);
	}
	return (0);
}

int	get_stack(t_stack **stk, int argc, char *argv[])
{
	int	i;
	int	num;

	i = 1;
	*stk = NULL;
	while (i < argc)
	{
		if (parse_int(&num, argv[i++]) && !has_double(stk, num))
			ft_stkadd_back(stk, ft_stknew(num));
		else
			return (0);
	}
	return (1);
}