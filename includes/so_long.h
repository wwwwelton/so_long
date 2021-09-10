/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:21:11 by wleite            #+#    #+#             */
/*   Updated: 2021/09/10 15:06:44 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	int 	img_height;
	char	**map;
	int		win_width;
	int		win_height;
}	t_game;

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../sources/libft/libft.h"
# include "../sources/minilibx/mlx.h"

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

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
