#include "../includes/push_swap.h"

char	*three_sort(t_stack **stk_a)
{
	if (is_stk_sorted(stk_a))
		return ("");
	if ((*stk_a)->num < (*stk_a)->next->num)
	{
		if ((*stk_a)->num < (*stk_a)->next->next->num)
			return (RROT_A SWAP_A);
		else
			return (RROT_A);
	}
	else
	{
		if ((*stk_a)->next->num < (*stk_a)->next->next->num)
		{
			if ((*stk_a)->num < (*stk_a)->next->next->num)
				return (SWAP_A);
			else
				return (ROT_A);
		}
		else
			return (SWAP_A RROT_A);
	}
}

int	get_rsteps(t_all *all)
{
	int		result;
	t_stack	*tmp;

	result = 0;
	tmp = *(all->stk_a);
	while (tmp && tmp->num != all->min)
	{
		result++;
		tmp = tmp->next;
	}
	if (result > ft_stksize(all->stk_a) - result)
		return (result - ft_stksize(all->stk_a));
	return (result);
}

char	*rot_stk_a(int r_steps, t_all *all, char *ops_line)
{
	if (r_steps > 0)
	{
		while (r_steps--)
		{
			rotate(all->stk_a);
			ops_line = gnl_strjoin(ops_line, ROT_A);
		}
	}
	else
	{
		while (r_steps++)
		{
			rev_rotate(all->stk_a);
			ops_line = gnl_strjoin(ops_line, RROT_A);
		}
	}
	return (ops_line);
}

char	*four_sort(t_all *all)
{
	char	*ops_line;
	char	*three_line;
	int		r_steps;

	if (is_stk_sorted(all->stk_a))
		return ("");
	ops_line = NULL;
	all->min = ft_stkmin(all->stk_a)->num;
	r_steps = get_rsteps(all);
	ops_line = rot_stk_a(r_steps, all, ops_line);
	push(all->stk_b, all->stk_a);
	ops_line = gnl_strjoin(ops_line, PUSH_B);
	three_line = three_sort(all->stk_a);
	do_stack_ops(all->stk_a, all->stk_b, three_line, 0);
	ops_line = gnl_strjoin(ops_line, three_line);
	push(all->stk_a, all->stk_b);
	ops_line = gnl_strjoin(ops_line, PUSH_A);
	return (ops_line);
}

char	*five_sort(t_all *all)
{
	char	*ops_line;
	char	*four_line;
	int		r_steps;

	ops_line = NULL;
	all->min = ft_stkmin(all->stk_a)->num;
	r_steps = get_rsteps(all);
	ops_line = rot_stk_a(r_steps, all, ops_line);
	push (all->stk_b, all->stk_a);
	ops_line = gnl_strjoin(ops_line, PUSH_B);
	four_line = four_sort(all);
	ops_line = gnl_strjoin(ops_line, four_line);
	free(four_line);
	push(all->stk_a, all->stk_b);
	ops_line = gnl_strjoin(ops_line, PUSH_A);
	return (ops_line);
}
