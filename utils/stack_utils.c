
#include "../includes/push_swap.h"

void	ft_stkadd_back(t_stack **stk, t_stack *new)
{
	t_stack *tmp;

	tmp = ft_stklast(*stk);
	if (tmp)
	{
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
	t_stack *tmp;

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


//void	ft_stkdelone(t_stack *stk)
//{
//	if (stk)
//	{
//		stk->next = NULL;
//		free(stk);
//		stk = NULL;
//	}
//}
//
//void	ft_stkiter(t_stack **stk, void (*f)(void *))
//{
//	t_stack *tmp;
//	
//	if (!stk || !f)
//		return ;
//	tmp = *stk;
//	while (tmp)
//	{
//		f(&tmp->num);
//		tmp = tmp->next;
//	}
//}

void	ft_stkshow(t_stack **stk)
{
	t_stack *tmp;
	
	if (!stk)
		return ;
	tmp = *stk;
	while (tmp)
	{
		printf("%5d, %d\n", tmp->num, tmp->steps);
		tmp = tmp->next;
	}
}

t_stack	*ft_stkmin(t_stack **stk)
{
	t_stack *min;
	t_stack *tmp;
	
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
	t_stack *new_el;

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


int		ft_stksize(t_stack **stk)
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