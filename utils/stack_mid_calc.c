#include "../includes/push_swap.h"

int	calc_middist(t_stack *el, t_stack **stk)
{
	t_stack	*tmp;
	int		lows;
	int		bigs;

	tmp = *stk;
	lows = 0;
	bigs = 0;
	while (tmp)
	{
		if (tmp->num > el->num)
			bigs++;
		if (tmp->num < el->num)
			lows++;
		tmp = tmp->next;
	}
	return ((lows > bigs) * (lows - bigs) + (lows <= bigs) * (bigs - lows));
}

int	ft_stkmid(t_stack **stk)
{
	t_stack	*tmp;

	if (!stk)
		return (0);
	tmp = *stk;
	while (tmp)
	{
		tmp->mid_dist = calc_middist(tmp, stk);
		tmp = tmp->next;
	}
	tmp = *stk;
	while (tmp)
	{
		if (tmp->mid_dist == 0)
			return (tmp->num);
		tmp = tmp->next;
	}
	tmp = *stk;
	while (tmp)
	{
		if (tmp->mid_dist == 1)
			return (tmp->num);
		tmp = tmp->next;
	}
	return (0);
}
