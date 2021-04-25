#include "../includes/push_swap.h"

char	*prep_b(t_all *all, int num, int steps, char *ol)
{
	if (steps < ft_stksize(all->stk_b) - steps)
	{
		while (*all->stk_b && (*all->stk_b)->num != num)
		{
			rotate(all->stk_b);
			ol = gnl_strjoin(ol, ROT_B);
		}
	}
	else
	{
		while (*all->stk_b && (*all->stk_b)->num != num)
		{
			rev_rotate(all->stk_b);
			ol = gnl_strjoin(ol, RROT_B);
		}
	}
	if (!ol)
		ol = gnl_strjoin(ol, "");
	return (ol);
}

char	*prep_a(t_all *all, int num, int steps, char *ol)
{
	if (steps < ft_stksize(all->stk_a) - steps)
	{
		while (*all->stk_a && !check_pos(*all->stk_a, num, all->min, all->max))
		{
			rotate(all->stk_a);
			ol = gnl_strjoin(ol, ROT_A);
		}
	}
	else
	{
		while (*all->stk_a && !check_pos(*all->stk_a, num, all->min, all->max))
		{
			rev_rotate(all->stk_a);
			ol = gnl_strjoin(ol, RROT_A);
		}
	}
	if (!ol)
		ol = gnl_strjoin(ol, "");
	return (ol);
}

char	*dif_prepare(t_all *all, int num)
{
	char	*ol;
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
	ol = prep_b(all, num, steps, ol);
	tmp = *all->stk_a;
	steps = 0;
	while (tmp && !check_pos(tmp, num, all->min, all->max))
	{
		steps++;
		tmp = tmp->next;
	}
	ol = prep_a(all, num, steps, ol);
	if (!ol)
		ol = gnl_strjoin(ol, "");
	return (ol);
}
