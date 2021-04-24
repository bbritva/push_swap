
#include "../includes/push_swap.h"

int		check_pos(t_stack *curr, int num, int min, int max)
{
	if ((curr->prev && (num > curr->prev->num && num < curr->num)) ||
		(num > ft_stklast(curr)->num && num < curr->num) ||
		(curr->num == min && num < curr->num) ||
		(curr->num == min && num > max))
		return (1);
	return (0);
}

int		get_str_steps(t_all *all, int num)
{
	int		result;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	result = 0;
	tmp_a = *(all->stk_a);
	tmp_b = *(all->stk_b);
	while ((tmp_b && tmp_b->num != num) && (tmp_a &&
		!check_pos(tmp_a, num, all->min, all->max)))
	{
		result++;
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
	}
	if (tmp_b && tmp_b->num == num)
	{
		while (tmp_a && !check_pos(tmp_a, num, all->min, all->max))
		{
			result++;
			tmp_a = tmp_a->next;
		}
	}
	else
	{
		while (tmp_b && tmp_b->num != num)
		{
			result++;
			tmp_b = tmp_b->next;
		}
	}
	return(result);
}

int		get_rev_steps(t_all *all, int num)
{
	int		result;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	result = 0;
	tmp_a = *(all->stk_a);
	tmp_b = *(all->stk_b);
	while ((tmp_b && tmp_b->num != num) && (tmp_a &&
		!check_pos(tmp_a, num,  all->min, all->max)))
	{
		result++;
		if (tmp_a->prev)
			tmp_a = tmp_a->prev;
		else
			tmp_a = ft_stklast(tmp_a);
		if (tmp_b->prev)
			tmp_b = tmp_b->prev;
		else
			tmp_b = ft_stklast(tmp_b);
	}
	if (tmp_b && tmp_b->num == num)
	{
		while (tmp_a && !check_pos(tmp_a, num, all->min, all->max))
		{
			result++;
			if (tmp_a->prev)
				tmp_a = tmp_a->prev;
			else
				tmp_a = ft_stklast(tmp_a);
		}
	}
	else
	{
		while (tmp_b && tmp_b->num != num)
		{
			result++;
			if (tmp_b->prev)
				tmp_b = tmp_b->prev;
			else
				tmp_b = ft_stklast(tmp_b);
		}
	}
	return(result);
}

int		get_diff_steps(t_all *all, int num)
{
	int		result;
	int		steps;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	result = 0;
	steps = 0;
	tmp_b = *(all->stk_b);
	while (tmp_b && tmp_b->num != num)
	{
		steps++;
		tmp_b = tmp_b->next;
	}
	steps = (steps > (ft_stksize(all->stk_b) - steps)) * (ft_stksize(all->stk_b) - 
			steps) + (steps <= (ft_stksize(all->stk_b) - steps)) * steps;
	tmp_a = *(all->stk_a);
	while (tmp_a && !check_pos(tmp_a, num, all->min, all->max))
	{
		result++;
		tmp_a = tmp_a->next;
	}
	result = (result > (ft_stksize(all->stk_a) - result)) * (ft_stksize(all->stk_a) -
		result) + (result <= (ft_stksize(all->stk_a) - result)) * result;
	return(steps + result);
}

void	get_each_steps(t_all *all)
{
	t_stack *tmp;
	int 	straight_steps;
	int 	reverse_steps;
	int 	diff_steps;

	tmp = *(all->stk_b);
	all->min = ft_stkmin(all->stk_a)->num;
	all->max = ft_stkmax(all->stk_a)->num;
	while(tmp)
	{
		straight_steps = get_str_steps(all, tmp->num);
		reverse_steps = get_rev_steps(all, tmp->num);
		diff_steps = get_diff_steps(all, tmp->num);
		if (straight_steps <= reverse_steps)
		{
			if (straight_steps <= diff_steps)
			{
				tmp->steps = straight_steps;
				tmp->flag = STRWAY;
			}
			else
			{
				tmp->steps = diff_steps;
				tmp->flag = DIFWAY;
			}
		}
		else
		{
			if (reverse_steps <= diff_steps)
			{
				tmp->steps = reverse_steps;
				tmp->flag = REVWAY;
			}
			else
			{
				tmp->steps = diff_steps;
				tmp->flag = DIFWAY;
			}
		}
		tmp = tmp->next;
	}
}
char	*ultimate_sort(t_all *all)
{
	char	*ops_line;
	char	*five_sort_line;

	if (is_stk_sorted(all->stk_a))
		return ("");
	ops_line = NULL;
	all->max = ft_stkmax(all->stk_a)->num;
	all->min = ft_stkmin(all->stk_a)->num;
	while (ft_stksize(all->stk_a) > 5)
	{
		push(all->stk_b, all->stk_a);
		ops_line = gnl_strjoin(ops_line, PUSH_B);
		if ((*all->stk_b)->num > (all->max + all->min) / 2)
		{
			rotate(all->stk_b);
			ops_line = gnl_strjoin(ops_line, ROT_B);
		}
	}
	five_sort_line = five_sort(all);
	ops_line = gnl_strjoin(ops_line, five_sort_line);
	free(five_sort_line);
	while(*(all->stk_b))
	{
		get_each_steps(all);
		ops_line = do_min_steps(all, ops_line);
	}
	ops_line = gnl_strjoin(ops_line, final_rotate(all->stk_a));
//	ft_putstr("Stack A:\n");
//	ft_stkshow(stk_a);
//	ft_putstr("Stack B:\n");
//	ft_stkshow(stk_b);
	return (ops_line);
}
