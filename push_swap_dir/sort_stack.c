#include "../includes/push_swap.h"

char	*three_sort(t_stack **stk_a)
{
	if (is_stk_sorted(stk_a))
		return ("");
	if ((*stk_a)->num < (*stk_a)->next->num)				//132;231
	{
		if ((*stk_a)->num < (*stk_a)->next->next->num)		//132
			return (RROT_A SWAP_A);
		else
			return (RROT_A);								//231
	}
	else													//213;321;312
	{
		if ((*stk_a)->next->num < (*stk_a)->next->next->num)//213;312
		{
			if ((*stk_a)->num < (*stk_a)->next->next->num)	//213
				return (SWAP_A);
			else
				return (ROT_A);							//312
		}
		else												//321
			return (SWAP_A RROT_A);
	}
}

int		get_rsteps(t_all *all)
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
		return(result - ft_stksize(all->stk_a));
	return(result);
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
	push (all->stk_b, all->stk_a);
	ops_line = gnl_strjoin(ops_line, PUSH_B);
	four_line = four_sort(all);
	ops_line = gnl_strjoin(ops_line, four_line);
	free(four_line);
	push(all->stk_a, all->stk_b);
	ops_line = gnl_strjoin(ops_line, PUSH_A);
	return (ops_line);
}

char	*sort_stack(t_all *all)
{
	int 	stk_size;

	stk_size = ft_stksize(all->stk_a);
	if (stk_size == 2)
		return ("ra\n");
	if (stk_size == 3)
		return(three_sort(all->stk_a));
	if (stk_size == 4)
		return(four_sort(all));
	if (stk_size == 5)
		return(five_sort(all));
	return(ultimate_sort(all));
}