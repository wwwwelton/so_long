LIBFT_PATH		=	./libraries/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./libraries/minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	=	so_long.c map_gen.c map_check.c map_init.c
SOURCES_FILES	+=	game_init.c game_utils.c img_init.c img_draw.c map_update.c
SOURCES_FILES	+=	hold_key.c map_init_utils.c map_update_utils.c free_fire.c
SOURCES_FILES	+=	map_resume.c game_hook.c map_check_utils.c player_update.c
SOURCES_FILES	+=	data_init.c

SOURCES_BONUS	=	free_fire_bonus.c game_hook_bonus.c game_init_bonus.c
SOURCES_BONUS	+=	game_utils_bonus.c img_draw_bonus.c
SOURCES_BONUS	+=	img_init_bonus.c map_check_bonus.c map_check_utils_bonus.c
SOURCES_BONUS	+=	map_gen_bonus.c map_init_bonus.c map_init_utils_bonus.c
SOURCES_BONUS	+=	map_resume_bonus.c map_update_bonus.c
SOURCES_BONUS	+=	map_update_utils_bonus.c so_long_bonus.c enemy_init_bonus.c
SOURCES_BONUS	+=	enemy_init_utils_bonus.c player_update_bonus.c
SOURCES_BONUS	+=	hold_key_bonus.c enemy_update_bonus.c
SOURCES_BONUS	+=	enemy_update_utils_bonus.c score_init_bonus.c
SOURCES_BONUS	+=	score_init_utils_bonus.c score_update_bonus.c
SOURCES_BONUS	+=	animate_bonus.c loop_hook_bonus.c data_init_bonus.c

SOURCES_DIR		=	sources
BONUS_DIR		=	sources_bonus

OBJ_DIR			=	objects

HEADER			=	$(SOURCES_DIR)/so_long.h
HEADER_BONUS	=	$(BONUS_DIR)/so_long_bonus.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
BONUS_FILES		=	$(addprefix $(BONUS_DIR)/, $(SOURCES_BONUS))

OBJECTS			=	$(SOURCES:$(SOURCES_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJECTS_BONUS	=	$(BONUS_FILES:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME			=	so_long
NAME_BONUS		=	so_long_bonus

CC				=	clang
RM				=	rm -rf

CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-L. -lXext -L. -lX11

$(OBJ_DIR)/%.o:		$(SOURCES_DIR)/%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o:		$(BONUS_DIR)/%.c $(HEADER_BONUS)
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

bonus:				$(NAME_BONUS)

$(NAME):			$(LIBFT) $(OBJ_DIR) $(MINILIBX) $(OBJECTS) $(HEADER)
					$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) \
					$(MLXFLAGS) -o $(NAME)

$(NAME_BONUS):		$(LIBFT) $(OBJ_DIR) $(MINILIBX) $(OBJECTS_BONUS) \
					$(HEADER_BONUS)
					$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIBFT) $(MINILIBX) \
					$(MLXFLAGS) -o $(NAME)
					cp $(NAME) $(NAME_BONUS)

$(LIBFT):
					$(MAKE) -C $(LIBFT_PATH) bonus

$(MINILIBX):
					$(MAKE) -C $(MINILIBX_PATH)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(MAKE) -C $(LIBFT_PATH) clean
					$(MAKE) -C $(MINILIBX_PATH) clean
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(MAKE) -C $(LIBFT_PATH) fclean
					$(RM) $(NAME) $(NAME_BONUS)

re:					fclean all

.PHONY:				all clean fclean re libft minilibx bonus
