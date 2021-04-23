
#include "../includes/push_swap.h"

t_stack		*get_min_steps_el(t_stack **stk)
{
	t_stack *min_steps_el;
	t_stack *tmp;
	
	min_steps_el = *stk;
	tmp = *stk;
	while (tmp)
	{
		if (min_steps_el->steps > tmp->steps)
			min_steps_el = tmp;
		tmp = tmp->next;
	}
	return (min_steps_el);
}

char 		*prepare_stacks(t_all *all, t_stack *el)
{
	char	*ol;

//	ft_putstr("Stack A:\n");
//	ft_stkshow(stk_a);
//	ft_putstr("Stack B:\n");
//	ft_stkshow(stk_b);
	if (el->flag & STRWAY)
		ol = str_prepare(all, el->num);
	if (el->flag & REVWAY)
		ol = rev_prepare(all, el->num);
	if (el->flag & DIFWAY)
		ol = dif_prepare(all, el->num);
//	ft_putstr("Stack A:\n");
//	ft_stkshow(stk_a);
//	ft_putstr("Stack B:\n");
//	ft_stkshow(stk_b);
	return (ol);
}

char 		*do_min_steps(t_all *all, char *ol)
{
	t_stack *min_steps_el;

	min_steps_el = get_min_steps_el(all->stk_b);
	ol = gnl_strjoin(ol, prepare_stacks(all, min_steps_el));
	ol = gnl_strjoin(ol, PUSH_A);
//	ft_putstr("Stack A:\n");
//	ft_stkshow(stk_a);
//	ft_putstr("Stack B:\n");
//	ft_stkshow(stk_b);
	push(all->stk_a, all->stk_b);
//	ft_putstr("Stack A:\n");
//	ft_stkshow(stk_a);
//	ft_putstr("Stack B:\n");
//	ft_stkshow(stk_b);
	return (ol);
}
