#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"
# include "../gnl_dir/get_next_line.h"


#include <stdio.h>


# define F_MISS_MSG "Error\nFile name missing\n"
# define M_ARGS_MSG "Error\nWrong arguments\n"
# define NREAD_MSG "Error\nCannot read file\n"

typedef struct		s_stack
{
	int 			num;
	int 			steps;
	char 			*ops_line;
	struct s_stack	*next;

}					t_stack;

void				ft_stkadd_back(t_stack **stk, t_stack *new);
void				ft_stkadd_front(t_stack **stk, t_stack *new);
void				ft_stkclear(t_stack **stk);
void				ft_stkdelone(t_stack *stk);
void				ft_stkiter(t_stack **stk, void (*f)(void *));
t_stack				*ft_stklast(t_stack *stk);
t_stack				*ft_stkprevlast(t_stack *stk);
t_stack				*ft_stknew(int num);
int					ft_stksize(t_stack **stk);
void				ft_stkshow(t_stack **stk);
t_stack				*ft_stkmin(t_stack **stk);
int				 	is_int(char *str);
int 				is_stk_sorted(t_stack **stk);
int 				do_sort(t_stack **stk_a, t_stack **stk_b);
int 				swap(t_stack **stk);
int 				push(t_stack ** stk_a, t_stack **stk_b);
int 				rotate(t_stack **stk);
int 				rev_rotate(t_stack **stk);
char				*sort_stack(t_stack **stk_a, t_stack **stk_b);
char				*five_sort(t_stack **stk_a, t_stack **stk_b);
char				*ultimate_sort(t_stack **stk_a, t_stack **stk_b);
void				get_each_steps(t_stack **stk_a, t_stack **stk_b);
void 				do_min_steps(t_stack **stk_a, t_stack **stk_b);

#endif
