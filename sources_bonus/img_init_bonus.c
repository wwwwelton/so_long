/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 03:01:02 by wleite            #+#    #+#             */
/*   Updated: 2021/09/16 00:34:10 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	game->img_enemy = img_initalize(IMG_ENEMY, game);
	game->player_w = img_initalize(PLAYER_W, game);
	game->player_a = img_initalize(PLAYER_A, game);
	game->player_s = img_initalize(PLAYER_S, game);
	game->player_d = img_initalize(PLAYER_D, game);
	game->player_dead = img_initalize(PLAYER_DEAD, game);
	game->enemy_w = img_initalize(ENEMY_W, game);
	game->enemy_a = img_initalize(ENEMY_A, game);
	game->enemy_s = img_initalize(ENEMY_S, game);
	game->enemy_d = img_initalize(ENEMY_D, game);
}
