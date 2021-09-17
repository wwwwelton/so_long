/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:21:11 by wleite            #+#    #+#             */
/*   Updated: 2021/09/17 05:21:26 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	void	*player_w;
	void	*player_a;
	void	*player_s;
	void	*player_d;
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
}	t_game;

typedef struct s_map
{
	int	col;
	int	row;
	int	e_count;
	int	s_count;
	int	c_count;
}	t_map;

# define DEBUG 0

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

# define PLAYER_W "assets/images/env_2/P_W.xpm"
# define PLAYER_A "assets/images/env_2/P_A.xpm"
# define PLAYER_S "assets/images/env_2/P_S.xpm"
# define PLAYER_D "assets/images/env_2/P_D.xpm"

# define SPRITE_SIZE 32

int		exit_game(t_game *game);
int		key_press(int keycode, t_game *game);
int		map_check(char **map, char *file);
int		map_resume(t_game *game);
void	change_position(char *pos, char *next_pos, char val, char new_val);
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
void	map_init_hook_p(t_game *game, int j, int i);
void	map_update(int keycode, t_game *game);
void	map_update_hook_p(t_game *game, int j, int i);
void	t_map_init(t_map *m);
void	update_direction(int player_direction, t_game *game);
void	update_player(int keycode, t_game *game);
char	**map_gen(char *path_to_file);

#endif
