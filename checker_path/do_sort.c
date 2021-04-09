
#include "../main.h"

char 	*get_ops_line()
{
	char *line;
	char *ops_line;
	int		i;

	i = 1;
	ops_line = NULL;
	while (i)
	{
		ops_line = gnl_strjoin(ops_line, line);
		ops_line = gnl_strjoin(ops_line, "\n");
		free(line);
		i = get_next_line(0, &line);
	}
	ops_line = gnl_strjoin(ops_line, line);
	free(line);
	return (ops_line);
}

int 	do_sort(t_stack **stk_a, t_stack **stk_b)
{
	char *ops_line;
	
	(void)stk_b;
	(void)stk_a;
	ops_line = get_ops_line();
	ft_putstr(ops_line);
	ft_putstr("\n");
	return (1);
}