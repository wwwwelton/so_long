/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:21:08 by wleite            #+#    #+#             */
/*   Updated: 2021/09/09 14:59:23 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

int	main(void)
{
	t_mlx	*mlx;
	t_img	img;

	double x_new;
	double c_re;
	double c_im;
	double x;
	double y;
	int iteration;
	int		row;
	int		col;
	int		max;

	max = 200;

	mlx = malloc(sizeof(t_mlx));

	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "A simple example");
	img.img_ptr = mlx_new_image(mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);

	row = 0;
	while (row < IMG_HEIGHT)
	{
		col = 0;
		while (col < IMG_WIDTH)
		{
			c_re = (col - IMG_WIDTH / 2) * 4.0 / IMG_WIDTH;
			c_im = (row - IMG_HEIGHT / 2) * 4.0 / IMG_WIDTH;
			x = 0;
			y = 0;
			iteration = 0;
			while (x * x + y * y <= 4 && iteration < max) {
				x_new = x * x - y * y + c_re;
				y = 2 * x * y + c_im;
				x = x_new;
				iteration++;
			}
			if (iteration < max)
				img.data[col * IMG_WIDTH + row] = 0xFFFFFF;
			else
				img.data[col * IMG_WIDTH + row] = 0x000000;
			col++;
		}
		row++;
	}

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img.img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}

//gcc main.c libmlx.a -L. -lXext -L. -lX11 && ./a.out
//img.data[count_h * IMG_WIDTH + count_w] = 0x12154;
