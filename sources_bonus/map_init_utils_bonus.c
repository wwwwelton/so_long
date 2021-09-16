/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 03:06:40 by wleite            #+#    #+#             */
/*   Updated: 2021/09/15 21:50:19 by wleite           ###   ########.fr       */
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
