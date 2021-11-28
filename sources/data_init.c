/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 02:17:51 by wleite            #+#    #+#             */
/*   Updated: 2021/11/28 12:36:55 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	data_init(t_game *game)
{
	get_window_size(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window
		(game->mlx, game->win_width, game->win_height, "so_long");
	game->moves = 0;
	game->collected = 0;
	game->collectable = 0;
	game->player_direction = 'd';
	game->end_game = 0;
}
