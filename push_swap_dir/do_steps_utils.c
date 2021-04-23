
#include "../includes/push_swap.h"

char 	*str_prepare(t_all *all, int num)
{
	char 	*ol;

	ol = NULL;
	while ((*all->stk_b && (*all->stk_b)->num != num) &&
		(*all->stk_a && !check_pos(*all->stk_a, num, all->min, all->max)))
	{
		ol = gnl_strjoin(ol, ROT_BOTH);
		rotate(all->stk_b);
		rotate(all->stk_a);
	}
	if (*all->stk_b && (*all->stk_b)->num == num)
	{
		while (*all->stk_a && !check_pos(*all->stk_a, num, all->min, all->max))
		{
			ol = gnl_strjoin(ol, ROT_A);
			rotate(all->stk_a);
		}
	}
	else
	{
		while (*all->stk_b && (*all->stk_b)->num != num)
		{
			ol = gnl_strjoin(ol, ROT_B);
			rotate(all->stk_b);
		}
	}
	if (ol)
		return(ol);
	return ("");
}

char 	*rev_prepare(t_all *all, int num)
{
	char 	*ol;

	ol = NULL;
	while ((*all->stk_b && (*all->stk_b)->num != num) &&
		(*all->stk_a && !check_pos(*all->stk_a, num, all->min, all->max)))
	{
		ol = gnl_strjoin(ol, RROT_BOTH);
		rev_rotate(all->stk_b);
		rev_rotate(all->stk_a);
	}
	if (*all->stk_b && (*all->stk_b)->num == num)
		while (*all->stk_a && !check_pos(*all->stk_a, num, all->min, all->max))
		{
			ol = gnl_strjoin(ol, RROT_A);
			rev_rotate(all->stk_a);
		}
	else
		while (*all->stk_b && (*all->stk_b)->num != num)
		{
			ol = gnl_strjoin(ol, RROT_B);
			rev_rotate(all->stk_b);
		}
	if (ol)
		return(ol);
	return ("");}

char 	*dif_prepare(t_all *all, int num)
{
	char 	*ol;
	int		steps;
	t_stack	*tmp;

	ol = NULL;
	steps = 0;
	tmp = *all->stk_b;
	while (tmp && tmp->num != num)
	{
		steps++;
		tmp = tmp->next;
	}
	if (steps < ft_stksize(all->stk_b) - steps)
		while (*all->stk_b && (*all->stk_b)->num != num)
		{
			rotate(all->stk_b);
			ol = gnl_strjoin(ol, ROT_B);
		}
	else
		while (*all->stk_b && (*all->stk_b)->num != num)
		{
			rev_rotate(all->stk_b);
			ol = gnl_strjoin(ol, RROT_B);
		}
	tmp = *all->stk_a;
	steps = 0;
	while (tmp && !check_pos(tmp, num, all->min, all->max))
	{
		steps++;
		tmp = tmp->next;
	}
	if (steps < ft_stksize(all->stk_a) - steps)
		while (*all->stk_a && !check_pos(*all->stk_a, num, all->min, all->max))
		{
			rotate(all->stk_a);
			ol = gnl_strjoin(ol, ROT_A);
		}
	else
		while (*all->stk_a && !check_pos(*all->stk_a, num, all->min, all->max))
		{
			rev_rotate(all->stk_a);
			ol = gnl_strjoin(ol, RROT_A);
		}
	if (ol)
		return(ol);
	return ("");
}