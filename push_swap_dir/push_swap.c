/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 18:59:31 by grvelva           #+#    #+#             */
/*   Updated: 2021/04/09 13:31:10 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int 	parse_error(t_stack **stk_a, t_stack **stk_b)
{
	ft_stkclear(stk_a);	
	ft_stkclear(stk_b);
	ft_putstr("Error\n");
	return (1);
}

int		parse_int(int *num, char *str)
{
	if (is_int(str))
	{
		*num = ft_atoi(str);
		return (1);
	}
	return (0);
}

int 	get_stack(t_stack **stk, int argc, char *argv[])
{
	int		i;
	int 	num;
	
	i = 1;
	*stk = NULL;
	while (i < argc)
	{
		if (parse_int(&num, argv[i++]))
			ft_stkadd_back(stk, ft_stknew(num));
		else
			return (0);
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	t_stack	**stk_a;
	t_stack	**stk_b;
	
	if (argc == 1)
		return (0);
	stk_a = (t_stack **)malloc(sizeof(t_stack *));
	stk_b = (t_stack **)malloc(sizeof(t_stack *));
	if (stk_a && stk_b)
	{
		*stk_b = NULL;
		if (!get_stack(stk_a, argc, argv) && parse_error(stk_a, stk_b))
			return (0);
		ft_stkshow(stk_a);
		ft_putstr("stack A:\n");
		ft_stkshow(stk_a);
		ft_putstr("stack B:\n");
		ft_stkshow(stk_b);
		if (is_stk_sorted(stk_a) && !(*stk_b))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
	else
		ft_putstr("Memory allocate error\n");
}
