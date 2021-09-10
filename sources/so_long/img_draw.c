/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:59:40 by wleite            #+#    #+#             */
/*   Updated: 2021/09/10 15:05:13 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	img_draw(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->win, img, x * SPRITE_SIZE, y * SPRITE_SIZE);
}
