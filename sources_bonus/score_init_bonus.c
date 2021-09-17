/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 01:55:03 by wleite            #+#    #+#             */
/*   Updated: 2021/09/17 17:10:56 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	score_init(t_game *game)
{
	game->map[0][0] = -120;
	game->map[0][1] = -121;
	game->map[0][2] = -122;
	game->map[0][3] = -110;
	game->map[0][4] = -110;
	game->map[0][5] = -110;
	game->map[0][6] = -125;
}
