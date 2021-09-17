/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:38:58 by wleite            #+#    #+#             */
/*   Updated: 2021/09/17 00:52:04 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_updater(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
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
			else if (is_enemy(game->map[i][j]))
				map_update_hook_e(game, j, i);
			else if (is_score(game->map[i][j]))
				map_update_hook_s(game, j, i);
		}
	}
}

void	map_update(int keycode, t_game *game)
{
	update_direction(keycode, game);
	update_player(keycode, game);
	map_updater(game);
}
