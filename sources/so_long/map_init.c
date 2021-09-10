/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 01:55:03 by wleite            #+#    #+#             */
/*   Updated: 2021/09/10 02:24:20 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_init(char **map, void	*mlx, void	*win)
{
	void	*img;
	int		img_width;
	int 	img_height;
	int		i;

	img = mlx_xpm_file_to_image(mlx, "assets/images/env_1/C.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);

	i = 0;
	while(i < 640)
	{
		if (map)
			mlx_put_image_to_window(mlx, win, img, i, 0);
		i += 32;
	}
}
