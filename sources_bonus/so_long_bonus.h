/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:21:11 by wleite            #+#    #+#             */
/*   Updated: 2021/09/16 19:43:35 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_space;
	void	*img_wall;
	void	*img_collect;
	void	*img_exit;
	void	*img_player;
	void	*img_enemy;
	void	*player_w;
	void	*player_a;
	void	*player_s;
	void	*player_d;
	void	*player_dead;
	void	*enemy_w;
	void	*enemy_a;
	void	*enemy_s;
	void	*enemy_d;
	char	**map;
	int		player_direction;
	int		x;
	int		y;
	int		img_width;
	int		img_height;
	int		win_width;
	int		win_height;
	int		moves;
	int		collected;
	int		collectable;
	int		end_game;
	int		loops;
}	t_game;

typedef struct s_map
{
	int	col;
	int	row;
	int	e_count;
	int	s_count;
	int	c_count;
}	t_map;

# define DEBUG 1

# define GAME_SPEED 3000

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_DESTROY_NOTIFY 17
# define X_EVENT_FOCUS_IN 9

# define KEY_ESC 65307
# define KEY_Q 113

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define IMG_SPACE "assets/images/env_2/0.xpm"
# define IMG_WALL "assets/images/env_2/1.xpm"
# define IMG_COLLECT "assets/images/env_2/C.xpm"
# define IMG_EXIT "assets/images/env_2/E.xpm"
# define IMG_PLAYER "assets/images/env_2/P.xpm"
# define IMG_ENEMY "assets/images/env_2/EN.xpm"

# define PLAYER_W "assets/images/env_2/P_W.xpm"
# define PLAYER_A "assets/images/env_2/P_A.xpm"
# define PLAYER_S "assets/images/env_2/P_S.xpm"
# define PLAYER_D "assets/images/env_2/P_D.xpm"

# define PLAYER_DEAD "assets/images/env_2/P_DEAD.xpm"

# define ENEMY_W "assets/images/env_2/E_W.xpm"
# define ENEMY_A "assets/images/env_2/E_A.xpm"
# define ENEMY_S "assets/images/env_2/E_S.xpm"
# define ENEMY_D "assets/images/env_2/E_D.xpm"

# define SPRITE_SIZE 32

int		enemy_update(t_game *game);
int		exit_game(t_game *game);
int		is_enemy(char enemy);
int		key_press(int keycode, t_game *game);
int		map_check(char **map, char *file);
int		map_resume(t_game *game);
void	change_position(char *pos, char *next_pos, char val, char new_val);
char	enemy_flip(char c);
void	enemy_init(t_game *game);
void	enemy_kill(t_game *game);
void	enemy_translate(t_game *game);
void	free_game(t_game *game);
void	free_map(char **map);
void	game_hook(t_game *game);
void	game_init(t_game *game);
void	get_window_size(t_game *game);
void	hold_key(t_game *game, int ny, int nx);
void	img_draw(t_game *game, void *img, int x, int y);
void	img_init(t_game *game);
void	map_init(t_game *game);
void	map_init_hook_c(t_game *game, int j, int i);
void	map_init_hook_e(t_game *game, int j, int i);
void	map_init_hook_p(t_game *game, int j, int i);
void	map_update(int keycode, t_game *game);
void	map_updater(t_game *game);
void	map_update_hook_e(t_game *game, int j, int i);
void	map_update_hook_p(t_game *game, int j, int i);
void	t_map_init(t_map *m);
void	update_direction(int player_direction, t_game *game);
void	update_player(int keycode, t_game *game);
char	**map_gen(char *path_to_file);

#endif
