
#include "../includes/push_swap.h"

char 	*str_prepare(t_stack **stk_a, t_stack **stk_b, int num)
{
	char 	*ol;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	ol = NULL;
	tmp_a = *stk_a;
	tmp_b = *stk_b;
	while ((tmp_b && tmp_b->num != num) && (tmp_a && !check_pos(tmp_a, num)))
	{
		ol = gnl_strjoin(ol, ROT_BOTH);
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
	}
	if (tmp_b && tmp_b->num == num)
	{
		while (tmp_a && !check_pos(tmp_a, num))
		{
			ol = gnl_strjoin(ol, ROT_A);
			tmp_a = tmp_a->next;
		}
	}
	else
	{
		while (tmp_b && tmp_b->num != num)
		{
			ol = gnl_strjoin(ol, ROT_B);
			tmp_b = tmp_b->next;
		}
	}
	return(ol);
}

char 	*rev_prepare(t_stack **stk_a, t_stack **stk_b, int num)
{
	char 	*ol;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	ol = gnl_strjoin(NULL, RROT_BOTH);
	tmp_a = ft_stklast(*stk_a);
	tmp_b = ft_stklast(*stk_b);
	while ((tmp_b && tmp_b->num != num) && (tmp_a && !check_pos(tmp_a, num)))
	{
		ol = gnl_strjoin(ol, RROT_BOTH);
		tmp_a = tmp_a->prev;
		tmp_b = tmp_b->prev;
	}
	if (tmp_b && tmp_b->num == num)
	{
		while (tmp_a && !check_pos(tmp_a, num))
		{
			ol = gnl_strjoin(NULL, RROT_A);
			tmp_a = tmp_a->prev;
		}
	}
	else
	{
		while (tmp_b && tmp_b->num != num)
		{
			ol = gnl_strjoin(NULL, RROT_B);
			tmp_b = tmp_b->next;
		}
	}
	return(ol);
}

char 	*dif_prepare(t_stack **stk_a, t_stack **stk_b, int num)
{
	char 	*ol;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	ol = NULL;
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