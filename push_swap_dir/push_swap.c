/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbritva <bbritva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 18:59:31 by grvelva           #+#    #+#             */
/*   Updated: 2021/04/17 18:31:49 by bbritva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putstr(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	else
		ft_putstr("NULL, wtf?\n");
}

int	parse_error_exit(t_all *all)
{
	ft_stkclear(all->stk_a);
	ft_stkclear(all->stk_b);
	free(all);
	ft_putstr("Error\n");
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	**stk_a;
	t_stack	**stk_b;
	t_all	*all;
	char	*ops_line;

	if (argc == 1)
		return (0);
	stk_a = (t_stack **)malloc(sizeof(t_stack *));
	stk_b = (t_stack **)malloc(sizeof(t_stack *));
	all = (t_all *)malloc(sizeof(t_all));
	if (stk_a && stk_b && all)
	{
		all->stk_a = stk_a;
		all->stk_b = stk_b;
		*stk_b = NULL;
		if (!get_stack(stk_a, argc, argv) && parse_error_exit(all))
			return (0);
		if (is_stk_sorted(stk_a) && !(*stk_b))
			return (0);
		else
		{
			ops_line = sort_stack(all);
			ft_putstr(ops_line);
		}
	}
}
