NAME		=	main
LIBFT		=	libft.a
CCF			=	@gcc $(CFLAGS)
MKLIB		=	@ar rc
RM			=	@rm -f
CFLAGS		=	-Wall -Wextra -Werror -g
CHECK_PATH	=	./checker/
PS_PATH		=	./push_swap/
SRCS		=	main.c GNL/get_next_line.c GNL/get_next_line_utils.c \
#				$(addprefix $(CHECK_PATH), *c) \
#				$(addprefix $(PS_PATH), *c)
OBJS		=	$(SRCS:.c=.o)
LIB_DIR		=	./libft/

HDR			=	main.h

all:		$(NAME)

clean:
			@make clean -C $(LIB_DIR)
			$(RM) $(OBJS)
			@echo objs deleted

fclean:		clean
			@make fclean -C $(LIB_DIR)
			$(RM) $(NAME)
			@echo $(NAME) deleted

re:			fclean all

$(NAME):	$(OBJS) $(HDR)
			@make bonus -C $(LIB_DIR)
			@mv $(LIB_DIR)$(LIBFT) $(LIBFT)
			$(CCF) $(OBJS) -o $(NAME)
			@echo $(NAME) compilled

%.o:		%.c $(HDR)
			$(CCF) -c $< -o $@
			@echo $@ compilled

norm:
			norminette main.c Render/*c Render/*h Parser/*c Parser/*h libft/*c libft/*h GNL/*c GNL/*h

.PHONY:		all clean fclean re so bonus norm
