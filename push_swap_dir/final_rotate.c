
#include "../includes/push_swap.h"

char 	*final_rotate(t_stack **stk)
{
	char	*ops_line;
	t_stack	*min_el;
	t_stack	*tmp;
	int 	steps;
	
	ops_line = NULL;
	min_el = ft_stkmin(stk);
	tmp = *stk;
	steps = 0;
	while (tmp && tmp->num != min_el->num)
	{
		steps++;
		tmp = tmp->next;
	}
	if (steps < ft_stksize(stk) - steps)
	{
		while ((*stk)->num != min_el->num)
		{
			rotate(stk);
			ops_line = gnl_strjoin(ops_line, ROT_A);
		}
	}
	else
	{
		while ((*stk)->num != min_el->num)
		{
			rev_rotate(stk);
			ops_line = gnl_strjoin(ops_line, RROT_A);
		}
	}
	return (ops_line);
}