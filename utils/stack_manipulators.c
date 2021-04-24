
#include "../includes/push_swap.h"

int 	swap(t_stack **stk)
{
	t_stack	*tmp;
	
	if (stk && *stk)
	{
		tmp = (*stk)->next;
		(*stk)->next = tmp->next;
		(*stk)->prev = tmp;
		(*stk)->next->prev = tmp->prev;
		tmp->next = *stk;
		tmp->prev = NULL;
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
		if (*stk_b)
			(*stk_b)->prev = NULL;
		tmp->next = NULL;
		ft_stkadd_front(stk_a, tmp);
	}
	return (3);	
}

int 	rotate(t_stack **stk)
{
	t_stack	*tmp;
	
	if (stk && *stk)
	{
		tmp = ft_stklast(*stk);
		tmp->next = *stk;
		(*stk)->prev = tmp;
		*stk = (*stk)->next;
		(*stk)->prev = NULL;
		tmp->next->next = NULL;
	}
	return (3);	
}

int 	rev_rotate(t_stack **stk)
{
	t_stack	*tmp;

	if (stk && *stk)
	{
		tmp = ft_stklast(*stk);
		tmp->next = *stk;
		(*stk)->prev = tmp;
		*stk = (*stk)->prev;
		(*stk)->prev->next = NULL;
		(*stk)->prev = NULL;
	}
	return (4);
}


