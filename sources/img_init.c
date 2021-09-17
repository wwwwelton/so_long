/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 03:01:02 by wleite            #+#    #+#             */
/*   Updated: 2021/09/17 05:20:08 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*img_initalize(char *img, t_game *game)
{
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image
		(game->mlx, img, &game->img_width, &game->img_height);
	return (img_ptr);
}

void	img_init(t_game *game)
{
	game->img_space = img_initalize(IMG_SPACE, game);
	game->img_wall = img_initalize(IMG_WALL, game);
	game->img_collect = img_initalize(IMG_COLLECT, game);
	game->img_exit = img_initalize(IMG_EXIT, game);
	game->img_player = img_initalize(IMG_PLAYER, game);
	game->player_w = img_initalize(PLAYER_W, game);
	game->player_a = img_initalize(PLAYER_A, game);
	game->player_s = img_initalize(PLAYER_S, game);
	game->player_d = img_initalize(PLAYER_D, game);
}
