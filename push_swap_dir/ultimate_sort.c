
#include "../includes/push_swap.h"

int		check_pos(int prev, t_stack *curr, int num)
{
	if (num > prev && num < curr->num)
		return (1);
	return (0);
}

int		get_str_steps(t_stack **stk_a, t_stack **stk_b, int num)
{
	int		result;
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		prev_num;

	result = 0;
	prev_num = ft_stklast(*stk_a)->num;
	tmp_a = *stk_a;
	tmp_b = *stk_b;
	while ((tmp_b && tmp_b->num != num) && (!check_pos(prev_num, tmp_a, num)))
	{
		result++;
		prev_num = tmp_a->num;
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
	}
	if (tmp_b && tmp_b->num == num)
	{
		while (!check_pos(prev_num, tmp_a, num))
		{
			result++;
			prev_num = tmp_a->num;
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
	int		prev_num;

	result = 0;
	prev_num = ft_stklast(*stk_a)->num;
	tmp_a = *stk_a;
	tmp_b = *stk_b;
	while ((tmp_b && tmp_b->num != num) && (!check_pos(prev_num, tmp_a, num)))
	{
		result++;
		prev_num = tmp_a->num;
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
	}
	if (tmp_b && tmp_b->num == num)
	{
		while (!check_pos(prev_num, tmp_a, num))
		{
			result++;
			prev_num = tmp_a->num;
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

int		get_diff_steps(t_stack **stk, int num)
{
	int		result;
	t_stack	*tmp;

	result = 0;
	tmp = *stk;
	while (tmp && tmp->num < num)
	{
		result++;
		tmp = tmp->next;
	}
	if (result > ft_stksize(stk) - result)
		return(result - ft_stksize(stk));
	return(result);
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
		diff_steps = get_diff_steps(stk_a, tmp->num);
		tmp = tmp->next;
	}
}
char	*ultimate_sort(t_stack **stk_a, t_stack **stk_b)
{
	char	*ops_line;

	if (is_stk_sorted(stk_a))
		return ("");
	while (ft_stksize(stk_a) > 5)
		push(stk_b, stk_a);
	ops_line = five_sort(stk_a, stk_b);
	while(*stk_b)
	{
		get_each_steps(stk_a, stk_b);
		do_min_steps(stk_a, stk_b);
	}
	return (ops_line);
}
