
#include "../includes/push_swap.h"

int 	swap(t_stack **stk)
{
	t_stack	*tmp;
	
	if (stk && *stk)
	{
		tmp = (*stk)->next;
		(*stk)->next = tmp->next;
		tmp->next = *stk;
		*stk = tmp;
		ft_putstr("swap done\n");
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
	t_stack	*tmp;
	
	if (stk && *stk)
	{
		tmp = ft_stklast(*stk);
		tmp->next = *stk;
		*stk = (*stk)->next;
		tmp->next->next = NULL;
		ft_putstr("rotate done\n");
	}
	else
		ft_putstr("nothing to rotate\n");
	return (3);	
}

int 	rev_rotate(t_stack **stk)
{
	t_stack	*tmp;
	t_stack	*new_last;

	if (stk && *stk)
	{
		new_last = ft_stkprevlast(*stk);
		tmp = *stk;
		*stk = ft_stklast(tmp);
		(*stk)->next = tmp;
		new_last->next = NULL;
		ft_putstr("rev_rotate done\n");
	}
	else
		ft_putstr("nothing to rev_rotate\n");
	return (4);
}


