#include "../includes/push_swap.h"

char	*three_sort(t_stack **stk_a)
{
//	ft_stkshow(stk_a);
	if ((*stk_a)->num < (*stk_a)->next->num)				//132;231
	{
		if ((*stk_a)->num < (*stk_a)->next->next->num)		//132
			return ("rra\nsa\n");
		else
			return ("rra\n");								//231
	}
	else													//213;321;312
	{
		if ((*stk_a)->next->num < (*stk_a)->next->next->num)//213;312
		{
			if ((*stk_a)->num < (*stk_a)->next->next->num)	//213
				return ("sa\n");
			else
				return ("ra\n");							//312
		}
		else												//321
			return ("sa\nrra\n");
	}
}

int		get_rsteps(t_stack **stk, int num)
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

char	*four_sort(t_stack **stk_a, t_stack **stk_b)
{
	char	*ops_line;
	t_stack *min;
	int		r_steps;

	ops_line = NULL;
	min = ft_stkmin(stk_a);
	r_steps = get_rsteps(stk_a, min->num);
	if (r_steps > 0)
	{
		while (r_steps--)
		{
			rotate(stk_a);
			ops_line = gnl_strjoin(ops_line, "ra\n");
		}
	}
	else
	{
		while (r_steps++)
		{
			rev_rotate(stk_a);
			ops_line = gnl_strjoin(ops_line, "rra\n");
		}
	}
	push (stk_b, stk_a);
//	ft_putstr("stack A:\n");
//	ft_stkshow(stk_a);
//	ft_putstr("stack B:\n");
//	ft_stkshow(stk_b);
	ops_line = gnl_strjoin(ops_line, "pb\n");
	ops_line = gnl_strjoin(ops_line, three_sort(stk_a));
	push(stk_a, stk_b);
	ops_line = gnl_strjoin(ops_line, "pa\n");
	return (ops_line);
}

char	*sort_stack(t_stack **stk_a, t_stack **stk_b)
{
	int 	stk_size;

	(void) stk_b;	
	stk_size = ft_stksize(stk_a);
	if (stk_size == 2)
		return ("ra\n");
	if (stk_size == 3)
		return(three_sort(stk_a));
	if (stk_size == 4)
		return(four_sort(stk_a, stk_b));
	return("NULL");
}