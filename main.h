#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"

# define F_MISS_MSG "Error\nFile name missing\n"
# define M_ARGS_MSG "Error\nWrong arguments\n"
# define NREAD_MSG "Error\nCannot read file\n"

typedef struct		s_stack
{
	int 			num;
	struct s_stack	*next;

}					t_stack;

void				ft_stkadd_back(t_stack **stk, t_stack *new);
void				ft_stkadd_front(t_stack **stk, t_stack *new);
void				ft_stkclear(t_stack **stk);
void				ft_stkdelone(t_stack *stk);
void				ft_stkiter(t_stack **stk, void (*f)(void *));
t_stack				*ft_stklast(t_stack *stk);
t_stack				*ft_stknew(int num);
int					ft_stksize(t_list *stk);

#endif
