/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hold_key_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 23:38:05 by wleite            #+#    #+#             */
/*   Updated: 2021/09/17 04:52:16 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	handle_0(t_game *game, int ny, int nx)
{
	int		gx;
	int		gy;

	gx = game->x;
	gy = game->y;
	change_position(&game->map[gy][gx], &game->map[ny][nx], '0', 'P');
	game->moves++;
}

static void	handle_c(t_game *game, int ny, int nx)
{
	int		gx;
	int		gy;

	gx = game->x;
	gy = game->y;
	change_position(&game->map[gy][gx], &game->map[ny][nx], '0', 'P');
	game->moves++;
	game->collected++;
}

static void	handle_e(t_game *game, int ny, int nx)
{
	int		gx;
	int		gy;

	gx = game->x;
	gy = game->y;
	change_position(&game->map[gy][gx], &game->map[ny][nx], '0', 'E');
	game->moves++;
	game->end_game = 1;
	game->end_game_win = 1;
}

static void	handle_en(t_game *game)
{
	game->player_direction = 'm';
	game->end_game = 1;
}

void	hold_key(t_game *game, int ny, int nx)
{
	if (game->map[ny][nx] == '0')
		handle_0(game, ny, nx);
	else if (game->map[ny][nx] == 'C')
		handle_c(game, ny, nx);
	else if (game->map[ny][nx] == 'E'
		&& (game->collected == game->collectable))
		handle_e(game, ny, nx);
	else if (is_enemy(game->map[ny][nx]))
		handle_en(game);
	else
		return ;
}
