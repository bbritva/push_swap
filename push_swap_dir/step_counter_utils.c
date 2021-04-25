#include "../includes/push_swap.h"

int	get_str_steps_util(t_all *all, t_stack *tmp_b, t_stack *tmp_a, int num)
{
	int	result;

	result = 0;
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
	return (result);
}

int	get_str_steps(t_all *all, int num)
{
	int		result;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	result = 0;
	tmp_a = *(all->stk_a);
	tmp_b = *(all->stk_b);
	while ((tmp_b && tmp_b->num != num) && (tmp_a && \
		!check_pos(tmp_a, num, all->min, all->max)))
	{
		result++;
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
	}
	result += get_str_steps_util(all, tmp_b, tmp_a, num);
	return (result);
}

t_stack	*step_back(t_stack *stk)
{
	if (stk->prev)
		stk = stk->prev;
	else
		stk = ft_stklast(stk);
	return (stk);
}

int	get_rev_steps_util(t_all *all, t_stack *tmp_b, t_stack *tmp_a, int num)
{
	int	result;

	result = 0;
	if (tmp_b && tmp_b->num == num)
	{
		while (tmp_a && !check_pos(tmp_a, num, all->min, all->max))
		{
			result++;
			tmp_a = step_back(tmp_a);
		}
	}
	else
	{
		while (tmp_b && tmp_b->num != num)
		{
			result++;
			tmp_b = step_back(tmp_b);
		}
	}
	return (result);
}

int	get_rev_steps(t_all *all, int num)
{
	int		result;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	result = 0;
	tmp_a = *(all->stk_a);
	tmp_b = *(all->stk_b);
	while ((tmp_b && tmp_b->num != num) && (tmp_a && \
		!check_pos(tmp_a, num, all->min, all->max)))
	{
		result++;
		tmp_a = step_back(tmp_a);
		tmp_b = step_back(tmp_b);
	}
	result += get_rev_steps_util(all, tmp_b, tmp_a, num);
	return (result);
}
