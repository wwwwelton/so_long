LIBFT_PATH		=	./libraries/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./libraries/minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	=	so_long.c map_gen.c map_check.c map_init.c
SOURCES_FILES	+=	game_init.c game_utils.c img_init.c img_draw.c map_update.c
SOURCES_FILES	+=	hold_key.c map_init_utils.c map_update_utils.c free_fire.c
SOURCES_FILES	+=	map_resume.c game_hook.c map_check_utils.c player_update.c

SOURCES_BONUS	=	free_fire_bonus.c game_hook_bonus.c game_init_bonus.c
SOURCES_BONUS	+=	game_utils_bonus.c img_draw_bonus.c
SOURCES_BONUS	+=	img_init_bonus.c map_check_bonus.c map_check_utils_bonus.c
SOURCES_BONUS	+=	map_gen_bonus.c map_init_bonus.c map_init_utils_bonus.c
SOURCES_BONUS	+=	map_resume_bonus.c map_update_bonus.c
SOURCES_BONUS	+=	map_update_utils_bonus.c so_long_bonus.c enemy_init_bonus.c
SOURCES_BONUS	+=	enemy_init_utils_bonus.c player_update_bonus.c
SOURCES_BONUS	+=	hold_key_bonus.c enemy_update.c enemy_update_utils.c
SOURCES_BONUS	+=	score_init_bonus.c score_init_utils_bonus.c
SOURCES_BONUS	+=	score_update_bonus.c animate_bonus.c loop_hook_bonus.c

SOURCES_DIR		=	sources

BONUS_DIR		=	sources_bonus

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

BONUS_FILES		=	$(addprefix $(BONUS_DIR)/, $(SOURCES_BONUS))

OBJECTS			= 	$(SOURCES:.c=.o)

OBJECTS_BONUS	= 	$(BONUS_FILES:.c=.o)

INCLUDES		=	./includes

NAME			=	so_long

NAME_BONUS		=	so_long_bonus

CC				=	gcc
RM				=	rm -f

# CFLAGS			=	-Wall -Wextra -Werror -no-pie -g3 -fsanitize=address
CFLAGS			=	-Wall -Wextra -Werror -no-pie -g3
MLXFLAGS		=	-L. -lXext -L. -lX11

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(LIBFT) $(MINILIBX) $(OBJECTS)
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -I $(INCLUDES) -o $(NAME)

$(NAME_BONUS):	$(LIBFT) $(MINILIBX) $(OBJECTS_BONUS)
				$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -I $(INCLUDES) -o $(NAME_BONUS)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

run:
				$(MAKE) && ./so_long "assets/maps/another_2.ber"

runb:
				$(MAKE) bonus && ./so_long_bonus "assets/maps/default_2.ber"

runbv:
				$(MAKE) bonus && valgrind -q --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./so_long_bonus "assets/maps/another_2.ber"

runv:
				$(MAKE) && valgrind -q --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./so_long assets/maps/another_2.ber

runiv:
				$(MAKE) && valgrind -q --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./so_long assets/maps/another.berr

norm:
				norminette $(SOURCES) ./includes/so_long.h

normb:
				norminette ./includes/so_long.h $(BONUS_DIR)

img:
				convert *.jpg -set filename:base "%[basename]" "%[filename:base].xpm"

.PHONY:			all clean fclean re libft minilibx bonus
