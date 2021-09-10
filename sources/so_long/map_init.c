/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 01:55:03 by wleite            #+#    #+#             */
/*   Updated: 2021/09/10 15:22:37 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_init(t_game *game)
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
			if (game->map[i][j] == '0')
				img_draw(game, game->img_space, j, i);
			if (game->map[i][j] == 'C')
				img_draw(game, game->img_collect, j, i);
			if (game->map[i][j] == 'E')
				img_draw(game, game->img_exit, j, i);
			if (game->map[i][j] == 'P')
				img_draw(game, game->img_player, j, i);
			j++;
		}
		i++;
	}
}
