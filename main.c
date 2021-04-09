/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 18:59:31 by grvelva           #+#    #+#             */
/*   Updated: 2021/04/09 09:24:12 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		check_main_input(int argc, char *argv[])
{
	if (argc == 1)
	{
		ft_putstr(F_MISS_MSG);
		return (0);
	}
	if (argc == 2 && ft_strlen(argv[1]) > 3 &&
		ft_strlen(ft_strnstr(argv[1], ".cub",
		ft_strlen(argv[1]))) == 4)
		return (1);
	if (argc == 3 && ft_strlen(argv[2]) == 6 &&
	ft_strlen(ft_strnstr(argv[2], "--save", ft_strlen(argv[1]))) == 6 &&
	ft_strlen(ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]))) == 4)
		return (1);
	ft_putstr(M_ARGS_MSG);
	return (0);
}

int		main(int argc, char *argv[])
{

	if (check_main_input(argc, argv)))
	{
		ft_putstr("args OK");
	}
	else
		ft_putstr("args BAD");
}
