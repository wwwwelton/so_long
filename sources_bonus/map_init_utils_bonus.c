/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 03:06:40 by wleite            #+#    #+#             */
/*   Updated: 2021/09/17 17:14:13 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_init_hook_c(t_game *game, int j, int i)
{
	img_draw(game, game->img_collect, j, i);
	game->collectable++;
}

void	map_init_hook_p(t_game *game, int j, int i)
{
	img_draw(game, game->img_player, j, i);
	game->x = j;
	game->y = i;
}

void	map_init_hook_e(t_game *game, int j, int i)
{
	if (game->map[i][j] == 'i')
		img_draw(game, game->enemy_w, j, i);
	else if (game->map[i][j] == 'j')
		img_draw(game, game->enemy_a, j, i);
	else if (game->map[i][j] == 'k')
		img_draw(game, game->enemy_s, j, i);
	else if (game->map[i][j] == 'l')
		img_draw(game, game->enemy_d, j, i);
	else
		return ;
}

static void	map_init_hook_s_digits(t_game *game, int j, int i)
{
	if (game->map[i][j] == -110)
		img_draw(game, game->mos_0, j, i);
	else if (game->map[i][j] == -111)
		img_draw(game, game->mos_1, j, i);
	else if (game->map[i][j] == -112)
		img_draw(game, game->mos_2, j, i);
	else if (game->map[i][j] == -113)
		img_draw(game, game->mos_3, j, i);
	else if (game->map[i][j] == -114)
		img_draw(game, game->mos_4, j, i);
	else if (game->map[i][j] == -115)
		img_draw(game, game->mos_5, j, i);
	else if (game->map[i][j] == -116)
		img_draw(game, game->mos_6, j, i);
	else if (game->map[i][j] == -117)
		img_draw(game, game->mos_7, j, i);
	else if (game->map[i][j] == -118)
		img_draw(game, game->mos_8, j, i);
	else if (game->map[i][j] == -119)
		img_draw(game, game->mos_9, j, i);
	else
		return ;
}

void	map_init_hook_s(t_game *game, int j, int i)
{
	map_init_hook_s_digits(game, j, i);
	if (game->map[i][j] == -120)
		img_draw(game, game->mov_1, j, i);
	else if (game->map[i][j] == -121)
		img_draw(game, game->mov_2, j, i);
	else if (game->map[i][j] == -122)
		img_draw(game, game->mov_3, j, i);
	else if (game->map[i][j] == -123)
		img_draw(game, game->mov_h, j, i);
	else if (game->map[i][j] == -124)
		img_draw(game, game->mov_h2, j, i);
	else if (game->map[i][j] == -125)
		img_draw(game, game->mov_0, j, i);
	else
		return ;
}
