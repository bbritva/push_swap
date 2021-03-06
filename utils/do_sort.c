#include "../includes/push_swap.h"

void 	do_stack_ops(t_stack **stk_a, t_stack **stk_b, char *ops_line, int i)
{
	while (ops_line && ops_line[i])
	{
		if (ft_strnstr(&ops_line[i], "sa\n", 3))
			i += swap(stk_a);
		if (ft_strnstr(&ops_line[i], "sb\n", 3))
			i += swap(stk_b);
		if (ft_strnstr(&ops_line[i], "ss\n", 3))
			i += swap(stk_a) + swap(stk_b) * 0;
		if (ft_strnstr(&ops_line[i], "pa\n", 3))
			i += push(stk_a, stk_b);
		if (ft_strnstr(&ops_line[i], "pb\n", 3))
			i += push(stk_b, stk_a);
		if (ft_strnstr(&ops_line[i], "ra\n", 3))
			i += rotate(stk_a);
		if (ft_strnstr(&ops_line[i], "rb\n", 3))
			i += rotate(stk_b);
		if (ft_strnstr(&ops_line[i], "rr\n", 3))
			i += rotate(stk_a) + rotate(stk_b) * 0;
		if (ft_strnstr(&ops_line[i], "rra\n", 4))
			i += rev_rotate(stk_a);
		if (ft_strnstr(&ops_line[i], "rrb\n", 4))
			i += rev_rotate(stk_b);
		if (ft_strnstr(&ops_line[i], "rrr\n", 4))
			i += rev_rotate(stk_a) + rev_rotate(stk_b) * 0;
	}
}

int	get_ops_line(char **ops_line)
{
	char	*line;
	int		i;

	*ops_line = NULL;
	i = get_next_line(0, &line);
	while (i && check_line(line))
	{
		*ops_line = gnl_strjoin(*ops_line, line);
		*ops_line = gnl_strjoin(*ops_line, "\n");
		free(line);
		i = get_next_line(0, &line);
	}
	if (!check_line(line) && i)
	{
		free(line);
		return (0);
	}
	*ops_line = gnl_strjoin(*ops_line, line);
	free(line);
	return (1);
}

int 	do_sort(t_stack **stk_a, t_stack **stk_b)
{
	char	*ops_line;
	int		i;

	i = 0;
	ops_line = NULL;
	if (get_ops_line(&ops_line))
	{
		do_stack_ops(stk_a, stk_b, ops_line, i);
		i = 1;
	}
	else
		i = 0;
	if (ops_line)
		free(ops_line);
	return (i);
}
