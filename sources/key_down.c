/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_down.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:16:08 by wleite            #+#    #+#             */
/*   Updated: 2021/09/17 05:20:08 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hold_down(t_game *game)
{
	int		x;
	int		y;

	x = game->x;
	y = game->y;
	if (game->map[y + 1][x] == '0')
	{
		change_position(&game->map[y][x], &game->map[y + 1][x], '0', 'P');
		game->moves++;
	}
	else if (game->map[y + 1][x] == 'C')
	{
		change_position(&game->map[y][x], &game->map[y + 1][x], '0', 'P');
		game->moves++;
		game->collected++;
	}
	else if (game->map[y + 1][x] == 'E'
		&& (game->collected == game->collectable))
	{
		change_position(&game->map[y][x], &game->map[y + 1][x], '0', 'E');
		game->moves++;
		game->end_game = 1;
	}
	else
		return ;
}
