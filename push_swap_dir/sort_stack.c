#include "../includes/push_swap.h"

char	*sort_stack(t_all *all)
{
	int	stk_size;

	stk_size = ft_stksize(all->stk_a);
	if (stk_size == 2)
		return ("ra\n");
	if (stk_size == 3)
		return (three_sort(all->stk_a));
	if (stk_size == 4)
		return (four_sort(all));
	if (stk_size == 5)
		return (five_sort(all));
	return (ultimate_sort(all));
}
