#include "../includes/push_swap.h"

t_stack	*ft_stkmin(t_stack **stk)
{
	t_stack	*min;
	t_stack	*tmp;

	if (!stk)
		return (NULL);
	tmp = *stk;
	min = tmp;
	while (tmp)
	{
		if (tmp->num < min->num)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_stack	*ft_stkmax(t_stack **stk)
{
	t_stack	*max;
	t_stack	*tmp;

	if (!stk)
		return (NULL);
	tmp = *stk;
	max = tmp;
	while (tmp)
	{
		if (tmp->num > max->num)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_stksize(t_stack **stk)
{
	int			stksize;
	t_stack		*tmp;

	stksize = 0;
	if (stk && *stk)
	{
		tmp = *stk;
		while (tmp)
		{
			stksize++;
			tmp = tmp->next;
		}
	}
	return (stksize);
}
