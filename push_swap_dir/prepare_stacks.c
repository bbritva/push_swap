#include "../includes/push_swap.h"

char 	*str_prepare_util(t_all *all, int num, char *ol)
{
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
	if (!ol)
		ol = gnl_strjoin(ol, "");
	return (ol);
}

char	*str_prepare(t_all *all, int num)
{
	char	*ol;

	ol = NULL;
	while ((*all->stk_b && (*all->stk_b)->num != num) && \
		(*all->stk_a && !check_pos(*all->stk_a, num, all->min, all->max)))
	{
		ol = gnl_strjoin(ol, ROT_BOTH);
		rotate(all->stk_b);
		rotate(all->stk_a);
	}
	ol = str_prepare_util(all, num, ol);
	return (ol);
}

char	*rev_prepare_util(t_all *all, int num, char *ol)
{
	if (*all->stk_b && (*all->stk_b)->num == num)
	{
		while (*all->stk_a && !check_pos(*all->stk_a, num, all->min, all->max))
		{
			ol = gnl_strjoin(ol, RROT_A);
			rev_rotate(all->stk_a);
		}
	}
	else
	{
		while (*all->stk_b && (*all->stk_b)->num != num)
		{
			ol = gnl_strjoin(ol, RROT_B);
			rev_rotate(all->stk_b);
		}
	}
	if (!ol)
		ol = gnl_strjoin(ol, "");
	return (ol);
}

char	*rev_prepare(t_all *all, int num)
{
	char	*ol;

	ol = NULL;
	while ((*all->stk_b && (*all->stk_b)->num != num) && \
		(*all->stk_a && !check_pos(*all->stk_a, num, all->min, all->max)))
	{
		ol = gnl_strjoin(ol, RROT_BOTH);
		rev_rotate(all->stk_b);
		rev_rotate(all->stk_a);
	}
	ol = rev_prepare_util(all, num, ol);
	return (ol);
}
