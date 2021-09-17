/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 03:00:52 by wleite            #+#    #+#             */
/*   Updated: 2021/09/17 03:21:13 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	animate_collect(t_game *game, int frame)
{
	mlx_destroy_image(game->mlx, game->img_collect);
	if (frame == 1)
		game->img_collect = img_initalize(C_1, game);
	else if (frame == 2)
		game->img_collect = img_initalize(C_2, game);
	else if (frame == 3)
		game->img_collect = img_initalize(C_3, game);
	else if (frame == 4)
		game->img_collect = img_initalize(C_4, game);
	else if (frame == 5)
		game->img_collect = img_initalize(C_5, game);
}

void	animate(t_game *game)
{
	if (game->animations < ANIMATION_SPEED)
	{
		game->animations++;
		return ;
	}
	else
		game->animations = 0;
	if (game->frame < 5)
		game->frame++;
	else
		game->frame = 1;
	animate_collect(game, game->frame);
	map_updater(game);
}
