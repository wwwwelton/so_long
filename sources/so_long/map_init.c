/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 01:55:03 by wleite            #+#    #+#             */
/*   Updated: 2021/09/10 03:50:49 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_init(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while(game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, j * SPRITE_SIZE, i * SPRITE_SIZE);
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_space, j * SPRITE_SIZE, i * SPRITE_SIZE);
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_collect, j * SPRITE_SIZE, i * SPRITE_SIZE);
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, j * SPRITE_SIZE, i * SPRITE_SIZE);
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player, j * SPRITE_SIZE, i * SPRITE_SIZE);
			j++;
		}
		i++;
	}
}
