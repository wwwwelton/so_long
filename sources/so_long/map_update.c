/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:38:58 by wleite            #+#    #+#             */
/*   Updated: 2021/09/10 23:47:31 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void hold_w(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map[y - 1][x] == '0')
	{
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'P';
		game->moves++;
	}
	if (game->map[y - 1][x] == 'C')
	{
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'P';
		game->moves++;
		game->collected++;
	}
	if (game->map[y - 1][x] == 'E')
	{
		if (game->collected == game->collectable)
		{
			game->map[y][x] = '0';
			game->map[y - 1][x] = 'E';
			exit_game();
		}
	}
}

void	map_update(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		hold_w(game);
	map_init(game);
}
