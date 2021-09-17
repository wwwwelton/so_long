/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fire_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:09:57 by wleite            #+#    #+#             */
/*   Updated: 2021/09/16 21:02:12 by wleite           ###   ########.fr       */
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

static void	mlx_destroy_mov(t_game *game)
{
	mlx_destroy_image(game->mlx, game->mov_1);
	mlx_destroy_image(game->mlx, game->mov_2);
	mlx_destroy_image(game->mlx, game->mov_3);
	mlx_destroy_image(game->mlx, game->mov_h);
	mlx_destroy_image(game->mlx, game->mos_0);
	mlx_destroy_image(game->mlx, game->mos_1);
	mlx_destroy_image(game->mlx, game->mos_2);
	mlx_destroy_image(game->mlx, game->mos_3);
	mlx_destroy_image(game->mlx, game->mos_4);
	mlx_destroy_image(game->mlx, game->mos_5);
	mlx_destroy_image(game->mlx, game->mos_6);
	mlx_destroy_image(game->mlx, game->mos_7);
	mlx_destroy_image(game->mlx, game->mos_8);
	mlx_destroy_image(game->mlx, game->mos_9);
}

void	free_game(t_game *game)
{
	mlx_destroy_mov(game);
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
	mlx_destroy_image(game->mlx, game->player_dead);
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
