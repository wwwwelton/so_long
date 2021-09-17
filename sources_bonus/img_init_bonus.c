/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 03:01:02 by wleite            #+#    #+#             */
/*   Updated: 2021/09/17 01:28:53 by wleite           ###   ########.fr       */
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

static void	img_score_init(t_game *game)
{
	game->mov_1 = img_initalize(MOV_1, game);
	game->mov_2 = img_initalize(MOV_2, game);
	game->mov_3 = img_initalize(MOV_3, game);
	game->mov_h = img_initalize(MOV_H, game);
	game->mos_0 = img_initalize(MS_0, game);
	game->mos_1 = img_initalize(MS_1, game);
	game->mos_2 = img_initalize(MS_2, game);
	game->mos_3 = img_initalize(MS_3, game);
	game->mos_4 = img_initalize(MS_4, game);
	game->mos_5 = img_initalize(MS_5, game);
	game->mos_6 = img_initalize(MS_6, game);
	game->mos_7 = img_initalize(MS_7, game);
	game->mos_8 = img_initalize(MS_8, game);
	game->mos_9 = img_initalize(MS_9, game);
}

void	img_init(t_game *game)
{
	img_score_init(game);
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
