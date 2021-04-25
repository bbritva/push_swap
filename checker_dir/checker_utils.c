#include "../includes/push_swap.h"

int has_double(t_stack **stk, int num)
{
	t_stack *tmp;
	if (stk && *stk)
	{
		tmp = *stk;
		while (tmp)
		{
			if (tmp->num == num)
				return (1);
			tmp = tmp->next; 
		}
	}
	return (0);
}