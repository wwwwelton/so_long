/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:21:11 by wleite            #+#    #+#             */
/*   Updated: 2021/09/10 15:43:31 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../sources/libft/libft.h"
# include "../sources/minilibx/mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_space;
	void	*img_wall;
	void	*img_collect;
	void	*img_exit;
	void	*img_player;
	int		img_width;
	int		img_height;
	char	**map;
	int		win_width;
	int		win_height;
}	t_game;

typedef struct s_param{
	int		x;
	int		y;
	char	str[3];
}	t_param;

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_release 3
# define X_EVENT_KEY_EXIT 17

# define KEY_ESC 53
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define IMG_SPACE "assets/images/env_1/0.xpm"
# define IMG_WALL "assets/images/env_1/1.xpm"
# define IMG_COLLECT "assets/images/env_1/C.xpm"
# define IMG_EXIT "assets/images/env_1/E.xpm"
# define IMG_PLAYER "assets/images/env_1/P.xpm"

# define SPRITE_SIZE 32

char	**map_gen(char *path_to_file);
char	*get_next_line(int fd);

int		map_check(char **map);
void	map_init(t_game *game);
void	game_init(t_game *game);
void	get_window_size(t_game *game);
void	img_init(t_game *game);
void	img_draw(t_game *game, void *img, int x, int y);

#endif
