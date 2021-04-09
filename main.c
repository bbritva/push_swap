/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 18:59:31 by grvelva           #+#    #+#             */
/*   Updated: 2021/04/09 13:07:13 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void		parse_error(t_stack **stk_a, t_stack **stk_b)
{
	ft_stkclear(stk_a);	
	ft_stkclear(stk_b);
	ft_putstr("Error\n");
}

int		parse_int(int *num, char *str)
{
	*num = ft_atoi(str);
	return (1);
}

int		main(int argc, char *argv[])
{
	t_stack	**stk_a;
	t_stack	**stk_b;
	int 	i;
	int 	num;
	
	if (argc == 1)
		return (0);
	i = 1;
	stk_a = (t_stack **)malloc(sizeof(t_stack *));
	stk_b = (t_stack **)malloc(sizeof(t_stack *));
	if (stk_a && stk_b)
	{
		while (i < argc)
		{
			if (parse_int(&num, argv[i++]))
				ft_stkadd_back(stk_a, ft_stknew(num));
			else
				parse_error(stk_a, stk_b);
		}		
	}
	else
		ft_putstr("allocate Error\n");
}


//t_list				*ft_lstnew(void *content);
//void					ft_lstadd_front(t_list **lst, t_list *new);
//int					ft_lstsize(t_list *lst);
//t_list				*ft_lstlast(t_list *lst);
//void					ft_lstadd_back(t_list **lst, t_list *new);
//void					ft_lstdelone(t_list *lst, void (*del)(void *));
//void					ft_lstclear(t_list **lst, void (*del)(void *));
//void					ft_lstiter(t_list *lst, void (*f)(void *));
//t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),