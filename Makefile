NAME		=	checker
LIBFT		=	libft.a
CCF			=	@gcc $(CFLAGS)
RM			=	@rm -r
CFLAGS		=	-Wall -Wextra -Werror -g
CHECK_PATH	=	checker_dir/
PS_PATH		=	push_swap_dir/
GNL_PATH	=	gnl_dir/
CHK_SRCS	=	checker.c checker_utils.c stack_utils.c do_sort.c stack_manipulators.c
GNL_SRCS	=	get_next_line.c get_next_line_utils.c
PS_SRCS		=	
SRCS		=	$(addprefix $(CHECK_PATH), $(CHK_SRCS)) \
				$(addprefix $(GNL_PATH), $(GNL_SRCS))
#				$(addprefix $(PS_PATH), $(PS_SRCS))
OBJS		=	$(SRCS:.c=.o)
LIB_DIR		=	libft/
HDR			=	main.h $(GNL_PATH)/get_next_line.h
CYAN		=	\x1B[36m
MAGENTA		=	\x1B[35m
GREEN		=	\033[92m
ENDCOLOR	=	\x1B[0m

all:		$(NAME)


$(NAME):	$(OBJS) $(HDR)
			echo $(SRCS)
			echo $(OBJS)
			@make bonus -C $(LIB_DIR)
			@mv $(LIB_DIR)$(LIBFT) $(LIBFT)
			$(CCF) $(OBJS) $(LIBFT) -o $(NAME)
			@echo "${GREEN}"$(NAME)" is compiled${ENDCOLOR}"

clean:
			@make clean -C $(LIB_DIR)
			$(RM) $(OBJS)
			@echo objs deleted

fclean:		clean
			@make fclean -C $(LIB_DIR)
			$(RM) $(NAME)
			@echo $(NAME) deleted

re:			fclean all

%.o:		%.c $(HDR)
			$(CCF) -c $< -o $@
			@echo $@ compilled

norm:
			norminette main.c Render/*c Render/*h Parser/*c Parser/*h libft/*c libft/*h GNL/*c GNL/*h

.PHONY:		all clean fclean re so bonus norm
