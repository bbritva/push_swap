
#include "../includes/push_swap.h"

char				*ultimate_sort(t_stack **stk_a, t_stack **stk_b)
{
	char	*ops_line;
	
	while (ft_stksize(stk_a) > 5)
		push(stk_b, stk_a);
	ops_line = five_sort(stk_a, stk_b);
	
	return (ops_line);
}
