/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:21:11 by wleite            #+#    #+#             */
/*   Updated: 2021/09/14 03:17:25 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

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
}	t_game;

typedef struct s_map
{
	int	col;
	int	row;
	int	e_count;
	int	s_count;
	int	c_count;
}	t_map;

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define DEBUG 1

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_DESTROY_NOTIFY 17

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

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

char	**map_gen(char *path_to_file);
char	*get_next_line(int fd);

int		map_check(char **map);
void	map_init(t_game *game);
void	game_init(t_game *game);
void	get_window_size(t_game *game);
void	img_init(t_game *game);
void	img_draw(t_game *game, void *img, int x, int y);
int		key_press(int keycode, t_game *game);
void	map_update(int keycode, t_game *game);
void	change_position(char *pos, char *next_pos, char val, char new_val);

void	hold_w(t_game *game);
void	hold_a(t_game *game);
void	hold_s(t_game *game);
void	hold_d(t_game *game);

void	map_init_hook_c(t_game *game, int j, int i);
void	map_init_hook_p(t_game *game, int j, int i);

void	map_update_hook_p(t_game *game, int j, int i);

void	free_map(char **map);
void	free_game(t_game *game);
int		exit_game(t_game *game);

void	update_direction(int player_direction, t_game *game);

#endif
