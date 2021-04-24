#include "../includes/push_swap.h"

void	ft_stkadd_back(t_stack **stk, t_stack *new)
{
	t_stack	*tmp;

	tmp = ft_stklast(*stk);
	if (tmp)
	{
		if (new)
			new->prev = tmp;
		tmp->next = new;
	}
	else
		*stk = new;
}

void	ft_stkadd_front(t_stack **stk, t_stack *new)
{
	if (stk)
	{
		if (*stk)
		{
			(*stk)->prev = new;
			new->next = *stk;
		}
		*stk = new;
	}
}

void	ft_stkclear(t_stack **stk)
{
	t_stack	*tmp;

	if (!stk)
		return ;
	while (*stk)
	{
		tmp = *stk;
		*stk = tmp->next;
		free(tmp);
	}
	*stk = NULL;
	free(stk);
}

t_stack	*ft_stklast(t_stack *stk)
{
	if (stk)
	{
		while (stk->next)
			stk = stk->next;
		return (stk);
	}
	return (NULL);
}

t_stack	*ft_stknew(int num)
{
	t_stack	*new_el;

	new_el = (t_stack *)malloc(sizeof(t_stack));
	if (new_el)
	{
		new_el->num = num;
		new_el->steps = 0;
		new_el->flag = 0;
		new_el->next = NULL;
		new_el->prev = NULL;
		return (new_el);
	}
	return (NULL);
}
