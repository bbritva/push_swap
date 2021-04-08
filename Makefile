NAME		=	cub3D
LIBFT		=	libft.a
CCF			=	@gcc $(CFLAGS)
MKLIB		=	@ar rc
RM			=	@rm -f
CFLAGS		=	-Wall -Wextra -Werror -g
PARSER_PATH	=	./Parser/
RENDER_PATH	=	./Render/
SRCS		=	main.c GNL/get_next_line.c GNL/get_next_line_utils.c \
				$(addprefix $(PARSER_PATH), parser.c param_parser.c map_parser.c map_split.c parser_utils.c \
				map_checker.c get_sprites.c) \
				$(addprefix $(RENDER_PATH), render_utils.c drawers.c sprites_handler.c freeing.c \
				drawers_utils.c draw_sprites.c hooks.c movers.c render.c raycast.c get_shot.c)
OBJS		=	$(SRCS:.c=.o)
P_OBJS		=	$(P_SRCS:.c=.o)
LIB_DIR		=	./libft/
MLIB_DIR	=	./minilibx/
MNAME		=	libmlx.dylib

HDR			=	cub3d.h Parser/parser.h Render/render.h GNL/get_next_line.h libft/libft.h

all:		$(NAME)

clean:
			@make clean -C $(LIB_DIR)
			@make clean -C $(MLIB_DIR)
			$(RM) $(OBJS)
			@echo objs deleted

fclean:		clean
			@make fclean -C $(LIB_DIR)
			$(RM) $(NAME)
			@echo $(NAME) deleted
			$(RM) $(MNAME)
			@echo $(MNAME) deleted

re:			fclean all

$(NAME):	$(OBJS) $(HDR)
			@make bonus -C $(LIB_DIR)
			$(CCF) $(OBJS) -lXext -lX11 -lm -lz minilibx/libmlx.a libft/libft.a -o $(NAME)
			@echo $(NAME) compilled

%.o:		%.c $(HDR)
			$(CCF) -lXext -lX11 -lm -lz minilibx/libmlx.a libft/libft.a 
			@echo $@ compilled

norm:
			norminette main.c Render/*c Render/*h Parser/*c Parser/*h libft/*c libft/*h GNL/*c GNL/*h

.PHONY:		all clean fclean re so bonus norm $(NAME)
