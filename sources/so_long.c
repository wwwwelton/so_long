/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:21:08 by wleite            #+#    #+#             */
/*   Updated: 2021/09/11 03:58:03 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	setbuf(stdout, NULL);
	if (argc == 2)
	{
		game.map = map_gen(argv[1]);
		if (map_check(game.map))
		{
			game_init(&game);
			img_init(&game);
			map_init(&game);
			mlx_hook(game.win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, &game);
			mlx_hook(game.win, X_EVENT_DESTROY_NOTIFY, 0, &exit_game, &game);
			mlx_loop(game.mlx);
		}
		else
			printf("Error!\nInvalid map!\n");
	}
	else
		printf("No map specified.\n");
	return (0);
}
