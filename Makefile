LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	=	so_long.c map_gen.c get_next_line.c map_check.c map_init.c
SOURCES_FILES	+=	game_init.c game_utils.c img_init.c img_draw.c map_update.c
SOURCES_FILES	+=	key_w.c key_a.c key_s.c key_d.c map_init_utils.c
SOURCES_FILES	+=	map_update_utils.c

SOURCES_DIR		=	sources

SOURCES			=	$(addprefix $(SOURCES_DIR)/so_long/, $(SOURCES_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

INCLUDES		=	includes

NAME			=	so_long

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror -no-pie -g3 -fsanitize=address
MLXFLAGS		=	-L. -lXext -L. -lX11

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(LIBFT) $(MINILIBX) $(OBJECTS)
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -I $(INCLUDES) -o $(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJECTS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(NAME)

re:				fclean all

run:
				$(MAKE) && ./so_long "assets/maps/another.ber"

runv:
				$(MAKE) && valgrind ./so_long "assets/maps/another.ber"

norm:
				norminette $(SOURCES) ./includes/so_long.h

.PHONY:			all clean fclean re libft minilibx
