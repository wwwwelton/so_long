/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:21:08 by wleite            #+#    #+#             */
/*   Updated: 2021/09/10 16:57:09 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		param->x++;
	else if (keycode == KEY_S)
		param->x--;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d\n", keycode);
	return (0);
}

void	param_init(t_param *param)
{
	param->x = 0;
	param->y = 0;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_param	param;

	if (argc == 2)
	{
		game.map = map_gen(argv[1]);
		if (map_check(game.map))
		{
			game_init(&game);
			img_init(&game);
			map_init(&game);
			param_init(&param);
			mlx_key_hook(game.win, &key_press, &param);
			mlx_loop(game.mlx);
		}
		else
			printf("Map error!\n");
	}
	else
		printf("No map specified.\n");
	return (0);
}
