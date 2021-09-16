/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fire_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:09:57 by wleite            #+#    #+#             */
/*   Updated: 2021/09/15 21:07:26 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		ft_free_ptr((void *)&map[i]);
		i++;
	}
	ft_free_ptr((void *)&map);
}

void	free_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_space);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_enemy);
	mlx_destroy_image(game->mlx, game->player_w);
	mlx_destroy_image(game->mlx, game->player_a);
	mlx_destroy_image(game->mlx, game->player_s);
	mlx_destroy_image(game->mlx, game->player_d);
	mlx_destroy_image(game->mlx, game->enemy_w);
	mlx_destroy_image(game->mlx, game->enemy_a);
	mlx_destroy_image(game->mlx, game->enemy_s);
	mlx_destroy_image(game->mlx, game->enemy_d);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_free_ptr(&game->mlx);
}

int	exit_game(t_game *game)
{
	free_map(game->map);
	free_game(game);
	exit(0);
	return (0);
}
