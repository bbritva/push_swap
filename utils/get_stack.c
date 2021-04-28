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

int	get_from_string(t_stack **stk, char *str)
{
	char	**nums;
	int		i;
	int		num;

	nums = ft_split(str, ' ');
	i = 0;
	while (nums[i])
	{
		if (parse_int(&num, nums[i]) && !has_double(stk, num))
			ft_stkadd_back(stk, ft_stknew(num));
		else
			return (0);
		i++;
	}
	return (1);
}

int	get_stack(t_stack **stk, int argc, char *argv[])
{
	int	i;
	int	num;

	i = 1;
	*stk = NULL;
	if (argc == 2)
		return (get_from_string(stk, argv[1]));
	while (i < argc)
	{
		if (parse_int(&num, argv[i++]) && !has_double(stk, num))
			ft_stkadd_back(stk, ft_stknew(num));
		else
			return (0);
	}
	return (1);
}
