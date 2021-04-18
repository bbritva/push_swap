
#include "../includes/push_swap.h"

int		get_upsteps(t_stack **stk, int num)
{
	int		result;
	t_stack	*tmp;

	result = 0;
	tmp = *stk;
	while (tmp && tmp->num != num)
	{
		result++;
		tmp = tmp->next;
	}
	if (result > ft_stksize(stk) - result)
		return(result - ft_stksize(stk));
	return(result);
}

int		get_prepare_position_steps(t_stack **stk, int num)
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
	int 	up_steps;
	int 	prepare_position_steps;

	tmp = *stk_b;
	while(tmp)
	{
		up_steps = get_upsteps(stk_b, tmp->num);
		prepare_position_steps = get_prepare_position_steps(stk_a, tmp->num);
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
