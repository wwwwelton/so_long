LIBFT_PATH		=	$(SOURCES_DIR)/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	$(SOURCES_DIR)/minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	=	so_long.c map_gen.c get_next_line.c map_check.c map_draw.c
SOURCES_FILES	+=	game_init.c

SOURCES_DIR		=	sources

SOURCES			=	$(addprefix $(SOURCES_DIR)/so_long/, $(SOURCES_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

INCLUDES		=	includes

NAME			=	so_long

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror -g3 -fsanitize=address
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
				$(MAKE) && ./so_long "assets/maps/default.ber"

.PHONY:			all clean fclean re libft minilibx
