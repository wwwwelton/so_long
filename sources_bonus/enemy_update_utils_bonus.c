/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_update_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 01:55:03 by wleite            #+#    #+#             */
/*   Updated: 2021/09/16 19:44:04 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	enemy_flip(char c)
{
	int		*b;
	size_t	r;

	b = malloc(sizeof(int) * 3);
	r = (size_t)b % 13;
	free(b);
	b = NULL;
	if (r > 0 && r < 4)
		c += r;
	else
		c += 1;
	if (c > 'l')
		c = 'i';
	return (c);
}

void	enemy_kill(t_game *game)
{
	game->end_game = 1;
	game->player_direction = 'm';
}

void	enemy_translate(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (is_enemy(ft_tolower(game->map[i][j])))
				game->map[i][j] = ft_tolower(game->map[i][j]);
			j++;
		}
		i++;
	}
}
