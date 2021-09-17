/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:16:08 by wleite            #+#    #+#             */
/*   Updated: 2021/09/17 05:20:08 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		hold_key(game, game->y - 1, game->x);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		hold_key(game, game->y, game->x - 1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		hold_key(game, game->y + 1, game->x);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		hold_key(game, game->y, game->x + 1);
	else
		return ;
}
