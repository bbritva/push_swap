
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

char 		*prepare_stacks(t_stack **stk_a, t_stack **stk_b, t_stack *el)
{
	char	*ol;
	
	if (el->flag & STRWAY)
		ol = str_prepare(stk_a, stk_b, el->num);
	if (el->flag & REVWAY)
		ol = rev_prepare(stk_a, stk_b, el->num);
	if (el->flag & DIFWAY)
		ol = dif_prepare(stk_a, stk_b, el->num);
	return (ol);
}

char 		*do_min_steps(t_stack **stk_a, t_stack **stk_b, char *ol)
{
	t_stack *min_steps_el;

	min_steps_el = get_min_steps_el(stk_b);
	ol = gnl_strjoin(ol, prepare_stacks(stk_a, stk_b, min_steps_el));
	ol = gnl_strjoin(ol, PUSH_A);
	push(stk_a, stk_b);
	return (ol);
}
