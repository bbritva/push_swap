CHK			=	checker
PS			=	push_swap
LIBFT		=	libft.a
CCF			=	@gcc $(CFLAGS)
RM			=	@rm -f
CFLAGS		=	-Wall -Wextra -Werror -g
CHECK_PATH	=	checker_dir/
CHK_SRCS	=	checker.c
PS_PATH		=	push_swap_dir/
PS_SRCS		=	push_swap.c sort_stack.c ultimate_sort.c do_steps.c prepare_stacks.c \
				final_rotate.c prepare_stacks_utils.c minimal_sort.c
UTL_PATH	=	utils/
UTL_SRCS	=	checker_utils.c stack_base_utils.c stack_manipulators.c do_sort.c \
				stack_ext_utils.c stack_mid_calc.c  
GNL_PATH	=	gnl_dir/
GNL_SRCS	=	get_next_line.c get_next_line_utils.c
SRCS_CHK	=	$(addprefix $(CHECK_PATH), $(CHK_SRCS)) \
				$(addprefix $(GNL_PATH), $(GNL_SRCS)) \
				$(addprefix $(UTL_PATH), $(UTL_SRCS))
SRCS_PS		=	$(addprefix $(GNL_PATH), $(GNL_SRCS)) \
				$(addprefix $(UTL_PATH), $(UTL_SRCS)) \
				$(addprefix $(PS_PATH), $(PS_SRCS))
OBJS_CHK	=	$(SRCS_CHK:.c=.o)
OBJS_PS		=	$(SRCS_PS:.c=.o)
LIB_DIR		=	libft/
HDR			=	includes/push_swap.h $(GNL_PATH)/get_next_line.h
CYAN		=	\x1B[36m
MAGENTA		=	\x1B[35m
GREEN		=	\033[92m
ENDCOLOR	=	\x1B[0m

all:		$(CHK) $(PS)

$(CHK):		$(OBJS_CHK) $(HDR)
			@make bonus -C $(LIB_DIR)
			@mv $(LIB_DIR)$(LIBFT) $(LIBFT)
			$(CCF) $(OBJS_CHK) $(LIBFT) -o $(CHK)
			@echo "${GREEN}"$(CHK)" is compiled${ENDCOLOR}"

$(PS):		$(OBJS_PS) $(HDR)
			@make bonus -C $(LIB_DIR)
			@mv $(LIB_DIR)$(LIBFT) $(LIBFT)
			$(CCF) $(OBJS_PS) $(LIBFT) -o $(PS)
			@echo "${GREEN}"$(PS)" is compiled${ENDCOLOR}"

clean:
			@make clean -C $(LIB_DIR)
			$(RM) $(LIBFT)
			$(RM) $(OBJS_CHK)
			$(RM) $(OBJS_PS)
			@echo objs deleted

fclean:		clean
			@make fclean -C $(LIB_DIR)
			$(RM) $(CHK)
			$(RM) $(PS)
			@echo $(CHK) deleted
			@echo $(PS) deleted

re:			fclean all

%.o:		%.c $(HDR)
			$(CCF) -c $< -o $@
			@echo $@ compilled

norm:
			norminette $(addprefix $(CHECK_PATH), $(CHK_SRCS)) $(addprefix $(GNL_PATH), $(GNL_SRCS)) $(addprefix $(UTL_PATH), $(UTL_SRCS)) $(addprefix $(PS_PATH), $(PS_SRCS))

.PHONY:		all clean fclean re so bonus norm
