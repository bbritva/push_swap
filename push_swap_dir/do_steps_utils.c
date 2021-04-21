
#include "../includes/push_swap.h"

char 	*str_prepare(t_stack **stk_a, t_stack **stk_b, int num)
{
	char 	*ol;

	ol = NULL;
	while ((*stk_b && (*stk_b)->num != num) && (*stk_a && !check_pos(*stk_a, num)))
	{
		ol = gnl_strjoin(ol, ROT_BOTH);
		rotate(stk_b);
		rotate(stk_a);
	}
	if (*stk_b && (*stk_b)->num == num)
	{
		while (*stk_a && !check_pos(*stk_a, num))
		{
			ol = gnl_strjoin(ol, ROT_A);
			rotate(stk_a);
		}
	}
	else
	{
		while (*stk_b && (*stk_b)->num != num)
		{
			ol = gnl_strjoin(ol, ROT_B);
			rotate(stk_b);
		}
	}
	return(ol);
}

char 	*rev_prepare(t_stack **stk_a, t_stack **stk_b, int num)
{
	char 	*ol;

	ol = gnl_strjoin(NULL, RROT_BOTH);
	while ((*stk_b && (*stk_b)->num != num) && (*stk_a && !check_pos(*stk_a, num)))
	{
		ol = gnl_strjoin(ol, RROT_BOTH);
		rev_rotate(stk_b);
		rev_rotate(stk_a);
	}
	if (*stk_b && (*stk_b)->num == num)
		while (*stk_a && !check_pos(*stk_a, num))
		{
			ol = gnl_strjoin(NULL, RROT_A);
			rev_rotate(stk_a);
		}
	else
		while (*stk_b && (*stk_b)->num != num)
		{
			ol = gnl_strjoin(NULL, RROT_B);
			rev_rotate(stk_b);
		}
	return(ol);
}

char 	*dif_prepare(t_stack **stk_a, t_stack **stk_b, int num)
{
	char 	*ol;
	int		steps;
	t_stack	*tmp;

	ol = NULL;
	steps = 0;
	tmp = *stk_b;
	while (tmp && tmp->num != num)
	{
		steps++;
		tmp = tmp->next;
	}
	if (steps < ft_stksize(stk_b) - steps)
		while (*stk_b && (*stk_b)->num != num)
		{
			rotate(stk_b);
			ol = gnl_strjoin(ol, ROT_B);
		}
	else
		while (*stk_b && (*stk_b)->num != num)
		{
			rev_rotate(stk_b);
			ol = gnl_strjoin(ol, RROT_B);
		}
	tmp = *stk_a;
	steps = 0;
	while (tmp && !check_pos(tmp, num))
	{
		steps++;
		tmp = tmp->next;
	}
	if (steps < ft_stksize(stk_b) - steps)
		while (*stk_a && !check_pos(*stk_a, num))
		{
			rotate(stk_a);
			ol = gnl_strjoin(ol, ROT_A);
		}
	else
		while (*stk_a && !check_pos(*stk_a, num))
		{
			rev_rotate(stk_a);
			ol = gnl_strjoin(ol, RROT_A);
		}
	return(ol);
}