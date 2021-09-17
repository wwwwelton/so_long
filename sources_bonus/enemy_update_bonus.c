/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 01:55:03 by wleite            #+#    #+#             */
/*   Updated: 2021/09/17 03:16:22 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	enemy_update_position(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'k' && game->map[i + 1][j] == '0')
		change_position(&game->map[i][j], &game->map[i + 1][j], '0', 'K');
	else if (game->map[i][j] == 'k' && game->map[i + 1][j] == 'P')
		enemy_kill(game);
	else if (game->map[i][j] == 'l' && game->map[i][j + 1] == '0')
		change_position(&game->map[i][j], &game->map[i][j + 1], '0', 'L');
	else if (game->map[i][j] == 'l' && game->map[i][j + 1] == 'P')
		enemy_kill(game);
	else if (game->map[i][j] == 'i' && game->map[i - 1][j] == '0')
		change_position(&game->map[i][j], &game->map[i - 1][j], '0', 'I');
	else if (game->map[i][j] == 'i' && game->map[i - 1][j] == 'P')
		enemy_kill(game);
	else if (game->map[i][j] == 'j' && game->map[i][j - 1] == '0')
		change_position(&game->map[i][j], &game->map[i][j - 1], '0', 'J');
	else if (game->map[i][j] == 'j' && game->map[i][j - 1] == 'P')
		enemy_kill(game);
	else
		game->map[i][j] = ft_toupper(enemy_flip(game->map[i][j]));
}

void	enemy_update(t_game *game)
{
	int		i;
	int		j;

	if (game->loops < GAME_SPEED || game->end_game)
	{
		game->loops++;
		return ;
	}
	else
		game->loops = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (is_enemy(game->map[i][j]))
				enemy_update_position(game, i, j);
			j++;
		}
		i++;
	}
	enemy_translate(game);
	map_updater(game);
}
