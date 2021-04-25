#include "../includes/push_swap.h"

int 	is_int(char *str)
{
	int			i;
	long long	num;
	int			sign;

	num = 0;
	i = 0;
	sign = 1;
	if (!str || !ft_strchr("-1234567890", str[i]))
		return (0);
	sign = -1 * (str[i] == '-') + 1 * (str[i] != '-');
	i = 1 * (str[i] == '-');
	while (str[i] && num <= 2147483647)
	{
		if (ft_isdigit(str[i]))
			num = num * 10 + str[i] - '0';
		else
			return (0);
		i++;
	}
	num *= sign;
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}

int 	is_stk_sorted(t_stack **stk)
{
	t_stack	*tmp;

	if (stk)
	{
		tmp = *stk;
		while (tmp->next)
		{
			if (tmp->next->num < tmp->num)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}

int has_double(t_stack **stk, int num)
{
	t_stack *tmp;
	if (stk && *stk)
	{
		tmp = *stk;
		while (tmp)
		{
			if (tmp->num == num)
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}

int check_line(char *line)
{
	if (ft_strnstr(line, "sa", 3) || ft_strnstr(line, "sb", 3))
		return (1);
	if (ft_strnstr(line, "ss", 3) || ft_strnstr(line, "pa", 3))
		return (1);
	if (ft_strnstr(line, "pb", 3) || ft_strnstr(line, "ra", 3))
		return (1);
	if (ft_strnstr(line, "rb", 3) || ft_strnstr(line, "rr", 3))
		return (1);
	if (ft_strnstr(line, "rra", 4) || ft_strnstr(line, "rrb", 4))
		return (1);
	if (ft_strnstr(line, "rrr", 4))
		return (1);
	return (0);
}