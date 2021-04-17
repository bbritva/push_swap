#include "../includes/push_swap.h"

char	*three_sort(t_stack **stk_a, t_stack **stk_b)
{
	if ((*stk_a)->num < )
}

char	*sort_stack(t_stack **stk_a, t_stack **stk_b)
{
	int 	stk_size;
	
	stk_size = ft_stksize(stk_a);
	if (stk_size == 2)
	{
		rotate(stk_a);
		return ("ra");
	}
	if (stk_size == 3)
		return(three_sort(stk_a, stk_b));
	return(NULL);
}