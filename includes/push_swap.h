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
# define SWAP_A "sa\n"
# define SWAP_B "sb\n"
# define SWAP_BOTH "ss\n"
# define PUSH_A "pa\n"
# define PUSH_B "pb\n"
# define ROT_A "ra\n"
# define ROT_B "rb\n"
# define ROT_BOTH "rr\n"
# define RROT_A "rra\n"
# define RROT_B "rrb\n"
# define RROT_BOTH "rrr\n"
# define STRWAY 1 << 0
# define REVWAY 1 << 1
# define DIFWAY 1 << 2


typedef struct		s_stack
{
	int 			num;
	int 			steps;
	char 			flag;
	struct s_stack	*prev;
	struct s_stack	*next;

}					t_stack;

void				ft_stkadd_back(t_stack **stk, t_stack *new);
void				ft_stkadd_front(t_stack **stk, t_stack *new);
void				ft_stkclear(t_stack **stk);
//void				ft_stkdelone(t_stack *stk);
//void				ft_stkiter(t_stack **stk, void (*f)(void *));
t_stack				*ft_stklast(t_stack *stk);
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
void			 	do_stack_ops(t_stack **stk_a, t_stack **stk_b,
						char *ops_line, int i);
char				*five_sort(t_stack **stk_a, t_stack **stk_b);
char				*ultimate_sort(t_stack **stk_a, t_stack **stk_b);
void				get_each_steps(t_stack **stk_a, t_stack **stk_b);
char 				*do_min_steps(t_stack **stk_a, t_stack **stk_b, char *ol);
int					check_pos(t_stack *curr, int num, int min);
char			 	*str_prepare(t_stack **stk_a, t_stack **stk_b, int num);
char 				*rev_prepare(t_stack **stk_a, t_stack **stk_b, int num);
char			 	*dif_prepare(t_stack **stk_a, t_stack **stk_b, int num);
char 				*final_rotate(t_stack **stk);
t_stack				*ft_stkmin(t_stack **stk);



#endif
