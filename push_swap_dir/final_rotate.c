#include "../includes/push_swap.h"

char	*do_rotations(t_stack **stk, int steps, t_stack *min_el, char *ol)
{
	if (steps < ft_stksize(stk) - steps)
	{
		while ((*stk)->num != min_el->num)
		{
			rotate(stk);
			ol = gnl_strjoin(ol, ROT_A);
		}
	}
	else
	{
		while ((*stk)->num != min_el->num)
		{
			rev_rotate(stk);
			ol = gnl_strjoin(ol, RROT_A);
		}
	}
	return (ol);
}

char	*final_rotate(t_stack **stk)
{
	char	*ops_line;
	t_stack	*min_el;
	t_stack	*tmp;
	int		steps;

	ops_line = NULL;
	min_el = ft_stkmin(stk);
	tmp = *stk;
	steps = 0;
	while (tmp && tmp->num != min_el->num)
	{
		steps++;
		tmp = tmp->next;
	}
	ops_line = do_rotations(stk, steps, min_el, ops_line);
	if (!ops_line)
		ops_line = gnl_strjoin(ops_line, "");
	return (ops_line);
}
