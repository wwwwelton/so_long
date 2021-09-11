/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:38:58 by wleite            #+#    #+#             */
/*   Updated: 2021/09/11 00:17:15 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_update(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		hold_w(game);
	// else if (keycode == KEY_A)
	// 	hold_a(game);
	// else if (keycode == KEY_S)
	// 	hold_s(game);
	// else if (keycode == KEY_D)
	// 	hold_d(game);
	else
		return ;
	map_init(game);
}
