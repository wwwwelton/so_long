/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:41:16 by wleite            #+#    #+#             */
/*   Updated: 2021/09/17 03:02:37 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_hook(t_game *game)
{
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, game);
	mlx_hook(game->win, X_EVENT_DESTROY_NOTIFY, 0, &exit_game, game);
	mlx_hook(game->win, X_EVENT_FOCUS_IN, 1L << 21, &map_resume, game);
	mlx_loop_hook(game->mlx, &loop_hook, game);
}
