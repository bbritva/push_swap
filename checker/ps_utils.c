
#include "../main.h"

void	ft_stkadd_back(t_stack **stk, t_stack *new)
{
	t_stack *tmp;

	tmp = ft_stklast(*stk);
	if (tmp)
		tmp->next = new;
	else
		*stk = new;
}

void	ft_stkadd_front(t_stack **stk, t_stack *new)
{
	new->next = *stk;
	*stk = new;
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


void	ft_stkdelone(t_stack *stk)
{
	if (stk)
	{
		stk->next = NULL;
		free(stk);
		stk = NULL;
	}
}

void	ft_stkiter(t_stack **stk, void (*f)(void *))
{
	t_stack *tmp;
	
	if (!stk || !f)
		return ;
	tmp = *stk;
	while (tmp)
	{
		f(&tmp->num);
		tmp = tmp->next;
	}
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

//
//t_stack	*ft_stkmap(t_stack *stk, void *(*f)(void *), void (*del)(void *))
//{
//	t_stack *result;
//	t_stack *tmp;
//
//	if (!f || !del)
//		return (NULL);
//	result = NULL;
//	while (stk)
//	{
//		if (!(tmp = ft_stknew(f(stk->num))))
//		{
//			ft_stkclear(&tmp, del);
//			return (NULL);
//		}
//		ft_lstadd_back(&result, tmp);
//		stk = stk->next;
//	}
//	return (result);
//}

t_stack	*ft_stknew(int num)
{
	t_stack *new_el;

	new_el = (t_stack *)malloc(sizeof(t_stack));
	if (new_el)
	{
		new_el->num = num;
		new_el->next = NULL;
		return (new_el);
	}
	return (NULL);
}


int	ft_stksize(t_list *stk)
{
	int stksize;

	stksize = 0;
	while (stk)
	{
		stksize++;
		stk = stk->next;
	}
	return (stksize);
}