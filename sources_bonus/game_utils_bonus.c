/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 02:46:04 by wleite            #+#    #+#             */
/*   Updated: 2021/09/17 02:05:34 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		printf("moves: %d\n", game->moves);
	}
	return (1);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit_game(game);
	else if (game->end_game)
		return (0);
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
	if (player_direction == KEY_W || player_direction == KEY_UP)
		game->player_direction = 'w';
	else if (player_direction == KEY_A || player_direction == KEY_LEFT)
		game->player_direction = 'a';
	else if (player_direction == KEY_S || player_direction == KEY_DOWN)
		game->player_direction = 's';
	else if (player_direction == KEY_D || player_direction == KEY_RIGHT)
		game->player_direction = 'd';
	else
		return ;
}
