/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:38:58 by wleite            #+#    #+#             */
/*   Updated: 2021/09/10 23:04:06 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_update(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (keycode == KEY_W)
	{
		if (game->map[x - 1][y] == '0')
		{
			game->map[x][y] = '0';
			game->map[x - 1][y] = 'P';
			game->moves++;
		}
	}
	map_init(game);
}
