/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 03:12:41 by wleite            #+#    #+#             */
/*   Updated: 2021/09/16 16:39:14 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_update_hook_e(t_game *game, int j, int i)
{
	if (game->map[i][j] == 'i')
		img_draw(game, game->enemy_w, j, i);
	else if (game->map[i][j] == 'j')
		img_draw(game, game->enemy_a, j, i);
	else if (game->map[i][j] == 'k')
		img_draw(game, game->enemy_s, j, i);
	else if (game->map[i][j] == 'l')
		img_draw(game, game->enemy_d, j, i);
}

void	map_update_hook_p(t_game *game, int j, int i)
{
	if (game->player_direction == 'w')
		img_draw(game, game->player_w, j, i);
	else if (game->player_direction == 'a')
		img_draw(game, game->player_a, j, i);
	else if (game->player_direction == 's')
		img_draw(game, game->player_s, j, i);
	else if (game->player_direction == 'd')
		img_draw(game, game->player_d, j, i);
	else if (game->player_direction == 'm')
		img_draw(game, game->player_dead, j, i);
	game->x = j;
	game->y = i;
}
