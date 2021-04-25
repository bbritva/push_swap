#include "../includes/push_swap.h"

int	check_pos(t_stack *curr, int num, int min, int max)
{
	if ((curr->prev && (num > curr->prev->num && num < curr->num)) || \
		(num > ft_stklast(curr)->num && num < curr->num) || \
		(curr->num == min && num < curr->num) || \
		(curr->num == min && num > max))
		return (1);
	return (0);
}

char	*pushing_b(t_all *all, char *ops_line)
{
	while (ft_stksize(all->stk_a) > 5)
	{
		push(all->stk_b, all->stk_a);
		ops_line = gnl_strjoin(ops_line, PUSH_B);
		if ((*all->stk_b)->num > all->mid)
		{
			rotate(all->stk_b);
			ops_line = gnl_strjoin(ops_line, ROT_B);
		}
	}
	return (ops_line);
}

char	*ultimate_sort(t_all *all)
{
	char	*ops_line;
	char	*five_sort_line;
	char	*final_rot_line;

	if (is_stk_sorted(all->stk_a))
		return ("");
	ops_line = NULL;
	all->mid = ft_stkmid(all->stk_a);
	ops_line = pushing_b(all, ops_line);
	five_sort_line = five_sort(all);
	ops_line = gnl_strjoin(ops_line, five_sort_line);
	free(five_sort_line);
	while (*(all->stk_b))
	{
		get_each_steps(all);
		ops_line = do_min_steps(all, ops_line);
	}
	final_rot_line = final_rotate(all->stk_a);
	ops_line = gnl_strjoin(ops_line, final_rot_line);
	free(final_rot_line);
	return (ops_line);
}
