
#include "../main.h"

int 	swap(t_stack **stk)
{
	t_stack	*tmp;
	
	if (stk && *stk)
	{
		tmp = (*stk)->next;
		(*stk)->next = tmp->next;
		tmp->next = *stk;
		*stk = tmp;
	}
	return (3);	
}

int 	push(t_stack **stk_a, t_stack **stk_b)
{
	t_stack *tmp;
	
	if (*stk_b)
	{
		tmp = *stk_b;
		*stk_b = (*stk_b)->next;
		ft_stkadd_front(stk_a, tmp);
		ft_putstr("push done\n");
	}
	else
		ft_putstr("nothing to push\n");
	return (3);	
}

int 	rotate(t_stack **stk)
{
	(void) stk;
	ft_putstr("rotate done\n");
	return (3);	
}

int 	rev_rotate(t_stack **stk)
{
	(void) stk;
	ft_putstr("rev_rotate done\n");
	return (4);	
}


