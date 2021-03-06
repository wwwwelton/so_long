/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 03:12:41 by wleite            #+#    #+#             */
/*   Updated: 2021/09/17 05:20:08 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	game->x = j;
	game->y = i;
}
