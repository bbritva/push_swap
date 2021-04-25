#include "../includes/push_swap.h"

int	get_diff_steps(t_all *all, int num)
{
	int		res;
	int		steps;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	res = 0;
	steps = 0;
	tmp_b = *(all->stk_b);
	while (tmp_b && tmp_b->num != num)
	{
		steps++;
		tmp_b = tmp_b->next;
	}
	steps = (steps > (ft_stksize(all->stk_b) - steps)) * (ft_stksize(all->stk_b)
			- steps) + (steps <= (ft_stksize(all->stk_b) - steps)) * steps;
	tmp_a = *(all->stk_a);
	while (tmp_a && !check_pos(tmp_a, num, all->min, all->max))
	{
		res++;
		tmp_a = tmp_a->next;
	}
	res = (res > (ft_stksize(all->stk_a) - res)) * (ft_stksize(all->stk_a)
			- res) + (res <= (ft_stksize(all->stk_a) - res)) * res;
	return (steps + res);
}

void	steps_handler(int str_steps, int rev_steps, int dif_steps, t_stack *stk)
{
	if (str_steps <= rev_steps && str_steps <= dif_steps)
	{
		stk->steps = str_steps;
		stk->flag = STRWAY;
	}
	if (str_steps > rev_steps && rev_steps <= dif_steps)
	{
		stk->steps = rev_steps;
		stk->flag = REVWAY;
	}
	if (str_steps > dif_steps && rev_steps > dif_steps)
	{
		stk->steps = dif_steps;
		stk->flag = DIFWAY;
	}
}

void	get_each_steps(t_all *all)
{
	t_stack	*tmp;
	int		straight_steps;
	int		reverse_steps;
	int		diff_steps;

	tmp = *(all->stk_b);
	all->min = ft_stkmin(all->stk_a)->num;
	all->max = ft_stkmax(all->stk_a)->num;
	while (tmp)
	{
		straight_steps = get_str_steps(all, tmp->num);
		reverse_steps = get_rev_steps(all, tmp->num);
		diff_steps = get_diff_steps(all, tmp->num);
		steps_handler(straight_steps, reverse_steps, diff_steps, tmp);
		tmp = tmp->next;
	}
}
