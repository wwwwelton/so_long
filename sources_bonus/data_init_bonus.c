/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 02:17:51 by wleite            #+#    #+#             */
/*   Updated: 2021/09/19 11:02:07 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	data_init(t_game *game)
{
	get_window_size(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window
		(game->mlx, game->win_width, game->win_height, "so_long_bonus");
	game->moves = 0;
	game->collected = 0;
	game->collectable = 0;
	game->player_direction = 'D';
	game->end_game = 0;
	game->end_game_win = 0;
	game->loops = 0;
	game->animations = 0;
	game->frame = 1;
}
