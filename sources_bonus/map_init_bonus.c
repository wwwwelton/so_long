/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 01:55:03 by wleite            #+#    #+#             */
/*   Updated: 2021/09/17 00:34:45 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_init(t_game *game)
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
				map_init_hook_c(game, j, i);
			else if (game->map[i][j] == 'E')
				img_draw(game, game->img_exit, j, i);
			else if (game->map[i][j] == 'P')
				map_init_hook_p(game, j, i);
			else if (is_enemy(game->map[i][j]))
				map_init_hook_e(game, j, i);
			else if (is_score(game->map[i][j]))
				map_init_hook_s(game, j, i);
		}
	}
}
