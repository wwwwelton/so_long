/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 02:46:04 by wleite            #+#    #+#             */
/*   Updated: 2021/09/14 22:30:25 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_window_size(t_game *game)
{
	int	i;

	i = 0;
	game->win_width = ft_strlen(game->map[i]) * SPRITE_SIZE;
	game->win_height = 0;
	while (game->map[i])
	{
		game->win_height++;
		i++;
	}
	game->win_height *= SPRITE_SIZE;
}

int	display_info(t_game *game)
{
	int	i;

	if (DEBUG)
	{
		i = 0;
		while (game->map[i])
		{
			printf("%s\n", game->map[i]);
			i++;
		}
		printf("collectable: %d\n", game->collectable);
		printf("collected: %d\n", game->collected);
		printf("player: X: %d | Y: %d | D: %c\n",
		game->x, game->y, ft_toupper(game->player_direction));
	}
	printf("moves: %d\n", game->moves);
	return (1);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else
	{
		map_update(keycode, game);
		display_info(game);
	}
	return (0);
}

void	change_position(char *pos, char *next_pos, char val, char new_val)
{
	*pos = val;
	*next_pos = new_val;
}

void	update_direction(int player_direction, t_game *game)
{
	game->player_direction = player_direction;
}
