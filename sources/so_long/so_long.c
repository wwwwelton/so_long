/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:21:08 by wleite            #+#    #+#             */
/*   Updated: 2021/09/10 04:13:45 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map = map_gen(argv[1]);
		if (map_check(game.map))
		{
			game_init(&game);
			img_init(&game);
			map_init(&game);
			mlx_loop(game.mlx);
		}
		else
			printf("Map error!\n");
	}
	else
		printf("No map specified.\n");
	return (0);
}
