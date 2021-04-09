NAME		=	checker
LIBFT		=	libft.a
CCF			=	@gcc $(CFLAGS)
MKLIB		=	@ar rc
RM			=	@rm -r
CFLAGS		=	-Wall -Wextra -Werror -g
CHECK_PATH	=	checker_path/
PS_PATH		=	push_swap_path/
CHK_SRCS	=	checker.c ps_utils.c
PS_SRCS		=	
SRCS		=	$(addprefix $(CHECK_PATH), $(CHK_SRCS)) \
#				$(addprefix $(PS_PATH), $(PS_SRCS))
BIN			=	objs/
MKDIR_BIN	=	$(shell mkdir -p $(BIN))
OBJS		=	$(addprefix $(BIN), $(CHK_SRCS:.c=.o $(PS_SRCS:.c=.o)))
LIB_DIR		=	libft/
HDR			=	main.h
CYAN		=	\x1B[36m
MAGENTA		=	\x1B[35m
GREEN		=	\033[92m
ENDCOLOR	=	\x1B[0m

all:		$(BIN) $(NAME)
$(NAME):	$(OBJS) $(HDR) $(MKDIR_BIN)
			@make bonus -C $(LIB_DIR)
			@mv $(LIB_DIR)$(LIBFT) $(LIBFT)
			$(CCF) $(OBJS) $(LIBFT) -o $(NAME)
			@echo "${GREEN}"$(NAME)" is compiled${ENDCOLOR}"
clean:
			@make clean -C $(LIB_DIR)
			$(RM) $(OBJS)
			$(RM) $(BIN)
			@echo objs deleted
fclean:		clean
			@make fclean -C $(LIB_DIR)
			$(RM) $(NAME)
			@echo $(NAME) deleted
re:			fclean all

$(BIN)%.o:	$(CHECK_PATH)%.c $(HDR)
			$(CCF) -c $< -o $@
			@echo $@ compilled

norm:
			norminette main.c Render/*c Render/*h Parser/*c Parser/*h libft/*c libft/*h GNL/*c GNL/*h

.PHONY:		all clean fclean re so bonus norm
