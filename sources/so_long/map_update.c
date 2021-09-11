/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:38:58 by wleite            #+#    #+#             */
/*   Updated: 2021/09/11 03:32:59 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	map_updater(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				img_draw(game, game->img_wall, j, i);
			else if (game->map[i][j] == '0')
				img_draw(game, game->img_space, j, i);
			else if (game->map[i][j] == 'C')
				img_draw(game, game->img_collect, j, i);
			else if (game->map[i][j] == 'E')
				img_draw(game, game->img_exit, j, i);
			else if (game->map[i][j] == 'P')
				map_update_hook_p(game, j, i);
			j++;
		}
		i++;
	}
}

void	map_update(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		hold_w(game);
	else if (keycode == KEY_A)
		hold_a(game);
	else if (keycode == KEY_S)
		hold_s(game);
	else if (keycode == KEY_D)
		hold_d(game);
	else
		return ;
	map_updater(game);
}
