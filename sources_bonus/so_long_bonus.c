/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:21:08 by wleite            #+#    #+#             */
/*   Updated: 2021/09/16 01:27:29 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	setbuf(stdout, NULL);
	if (argc == 2)
	{
		game.map = map_gen(argv[1]);
		if (map_check(game.map, argv[1]))
		{
			game_init(&game);
			img_init(&game);
			enemy_init(&game);
			map_init(&game);
			game_hook(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			printf("Error!\nInvalid map!\n");
			free_map(game.map);
			exit(0);
		}
	}
	else
		printf("No map specified.\n");
	return (0);
}
