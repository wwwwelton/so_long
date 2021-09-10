/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 01:55:03 by wleite            #+#    #+#             */
/*   Updated: 2021/09/10 03:12:36 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_init(t_game *game)
{
	int		i;

	mlx_put_image_to_window(game->mlx, game->win, game->img_wall, 0, 0);

	i = 0;
	while(i < 640)
	{
		if (game->map)
			mlx_put_image_to_window(game->mlx, game->win, game->img_wall, i, 0);
		i += 32;
	}
}
