
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

	if (el->flag & STRWAY)
		ol = str_prepare(all, el->num);
	if (el->flag & REVWAY)
		ol = rev_prepare(all, el->num);
	if (el->flag & DIFWAY)
		ol = dif_prepare(all, el->num);
	return (ol);
}

char 		*do_min_steps(t_all *all, char *ol)
{
	t_stack *min_steps_el;
	char 	*ops_line;

	min_steps_el = get_min_steps_el(all->stk_b);
	ops_line = prepare_stacks(all, min_steps_el);
	ol = gnl_strjoin(ol, ops_line);
	free(ops_line);
	ol = gnl_strjoin(ol, PUSH_A);
	push(all->stk_a, all->stk_b);
	return (ol);
}
