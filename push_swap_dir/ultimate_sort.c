
#include "../includes/push_swap.h"

int		check_pos(t_stack *curr, int num)
{
	if ((curr->prev && (num > curr->prev->num && num < curr->num)) ||
		(num > ft_stklast(curr)->num && num < curr->num))
			return (1);
	return (0);
}

int		get_str_steps(t_stack **stk_a, t_stack **stk_b, int num)
{
	int		result;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	result = 0;
	tmp_a = *stk_a;
	tmp_b = *stk_b;
	while ((tmp_b && tmp_b->num != num) && (tmp_a && !check_pos(tmp_a, num)))
	{
		result++;
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
	}
	if (tmp_b && tmp_b->num == num)
	{
		while (tmp_a && !check_pos(tmp_a, num))
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

int		get_rev_steps(t_stack **stk_a, t_stack **stk_b, int num)
{
	int		result;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	result = 1;
	tmp_a = ft_stklast(*stk_a);
	tmp_b = ft_stklast(*stk_b);
	while ((tmp_b && tmp_b->num != num) && (tmp_a && !check_pos(tmp_a, num)))
	{
		result++;
		tmp_a = tmp_a->prev;
		tmp_b = tmp_b->prev;
	}
	if (tmp_b && tmp_b->num == num)
	{
		while (tmp_a && !check_pos(tmp_a, num))
		{
			result++;
			tmp_a = tmp_a->prev;
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

int		get_diff_steps(t_stack **stk_a, t_stack **stk_b, int num)
{
	int		result;
	int		steps;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	result = 0;
	steps = 0;
	tmp_b = *stk_b;
	while (tmp_b && tmp_b->num != num)
	{
		steps++;
		tmp_b = tmp_b->next;
	}
	steps = (steps > (ft_stksize(stk_b) - steps)) * (ft_stksize(stk_b) - 
			steps) + (steps <= (ft_stksize(stk_b) - steps)) * steps;
	tmp_a = *stk_a;
	while (tmp_a && !check_pos(tmp_a, num))
	{
		result++;
		tmp_a = tmp_a->prev;
	}
	result = (result > (ft_stksize(stk_a) - result)) * (ft_stksize(stk_a) -
		result) + (result <= (ft_stksize(stk_a) - result)) * result;
	return(steps + result);
}

void	get_each_steps(t_stack **stk_a, t_stack **stk_b)
{
	t_stack *tmp;
	int 	straight_steps;
	int 	reverse_steps;
	int 	diff_steps;

	tmp = *stk_b;
	while(tmp)
	{
		straight_steps = get_str_steps(stk_a, stk_b, tmp->num);
		reverse_steps = get_rev_steps(stk_a, stk_b, tmp->num);
		diff_steps = get_diff_steps(stk_a, stk_b, tmp->num);
		if (straight_steps < reverse_steps)
		{
			if (straight_steps < diff_steps)
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
			if (reverse_steps < diff_steps)
			{
				tmp->steps = reverse_steps;
				tmp->flag = REVWAY;
			}
			else
			{
				tmp->steps = diff_steps;
				tmp->flag = REVWAY;
			}
		}
		tmp = tmp->next;
	}
}
char	*ultimate_sort(t_stack **stk_a, t_stack **stk_b)
{
	char	*ops_line;
	char	*five_sort_line;

	if (is_stk_sorted(stk_a))
		return ("");
	ops_line = NULL;
	while (ft_stksize(stk_a) > 5)
	{
		push(stk_b, stk_a);
		ops_line = gnl_strjoin(ops_line, PUSH_B);
	}
	five_sort_line = five_sort(stk_a, stk_b);
	ops_line = gnl_strjoin(ops_line, five_sort_line);
	free(five_sort_line);
	while(*stk_b)
	{
		get_each_steps(stk_a, stk_b);
		ops_line = do_min_steps(stk_a, stk_b, ops_line);
	}
	ops_line = gnl_strjoin(ops_line, final_rotate(stk_a));
	return (ops_line);
}
