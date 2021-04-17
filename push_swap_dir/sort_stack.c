#include "../includes/push_swap.h"

char	*three_sort(t_stack **stk_a)
{
	if ((*stk_a)->num < (*stk_a)->next->num)				//132;231
	{
		if ((*stk_a)->num < (*stk_a)->next->next->num)		//132
			return ("rra\nsa\n");
		else
			return ("rra\n");								//231
	}
	else													//213;321;312
	{
		if ((*stk_a)->next->num < (*stk_a)->next->next->num)//213;312
		{
			if ((*stk_a)->num < (*stk_a)->next->next->num)	//213
				return ("sa\n");
			else
				return ("ra\n");							//312
		}
		else												//321
			return ("sa\nrra\n");
	}
}

char	*sort_stack(t_stack **stk_a, t_stack **stk_b)
{
	int 	stk_size;

	(void) stk_b;	
	stk_size = ft_stksize(stk_a);
	if (stk_size == 2)
		return ("ra\n");
	if (stk_size == 3)
		return(three_sort(stk_a));
	return("NULL");
}