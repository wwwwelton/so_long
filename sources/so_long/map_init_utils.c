/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 03:06:40 by wleite            #+#    #+#             */
/*   Updated: 2021/09/11 03:08:49 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_init_hook_1(t_game *game, int j, int i)
{
	img_draw(game, game->img_wall, j, i);
}

void	map_init_hook_0(t_game *game, int j, int i)
{
	img_draw(game, game->img_space, j, i);
}

void	map_init_hook_c(t_game *game, int j, int i)
{
	img_draw(game, game->img_collect, j, i);
	game->collectable++;
}

void	map_init_hook_e(t_game *game, int j, int i)
{
	img_draw(game, game->img_exit, j, i);
}

void	map_init_hook_p(t_game *game, int j, int i)
{
	img_draw(game, game->img_player, j, i);
	game->x = j;
	game->y = i;
}
