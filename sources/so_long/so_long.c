/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:21:08 by wleite            #+#    #+#             */
/*   Updated: 2021/09/10 01:49:39 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int main(int argc, char **argv)
{
	char	**map;

	if (argc == 2)
	{
		map = map_gen(argv[1]);
		if (map_check(map))
			map_draw(map);
		else
			printf("Map error!");
	}
	else
		printf("No map specified.");
	return (0);
}

// int main()
// {
// 		void *mlx;
// 		void *win;
// 		void *img;
// 		void *img2;

// 		int	i;

// 		int		img_width;
// 		int 	img_height;

// 		mlx = mlx_init();
// 		win = mlx_new_window(mlx, 300, 300, "my_mlx");
// 		img = mlx_xpm_file_to_image(mlx, "assets/images/env_1/0.xpm", &img_width, &img_height);
// 		img2 = mlx_xpm_file_to_image(mlx, "assets/images/env_1/C.xpm", &img_width, &img_height);
// 		mlx_put_image_to_window(mlx, win, img, 0, 0);

// 		i = 0;
// 		while(i < 640)
// 		{
// 			mlx_put_image_to_window(mlx, win, img2, i, 0);
// 			i += 32;
// 		}

// 		i = 0;
// 		while(i < 640)
// 		{
// 			mlx_put_image_to_window(mlx, win, img2, 0, i);
// 			i += 32;
// 		}

// 		mlx_loop(mlx);
// 		return (0);
// }

//gcc main.c libmlx.a -L. -lXext -L. -lX11 && ./a.out
//img.data[count_h * IMG_WIDTH + count_w] = 0x12154;


