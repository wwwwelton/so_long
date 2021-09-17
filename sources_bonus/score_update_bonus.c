/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_update_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:38:58 by wleite            #+#    #+#             */
/*   Updated: 2021/09/17 05:03:24 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*moves_tostring(int moves)
{
	char	*str;
	char	*result;

	result = malloc(sizeof(char) * 4);
	if (!result)
		return (NULL);
	result[3] = '\0';
	ft_memset(result, '0', 3);
	str = ft_itoa(moves);
	if (moves < 10)
		result[2] = str[0];
	if (moves >= 10 && moves < 100)
	{
		result[1] = str[0];
		result[2] = str[1];
	}
	if (moves >= 100)
	{
		result[0] = str[0];
		result[1] = str[1];
		result[2] = str[2];
	}
	ft_free_ptr((void *)&str);
	return (result);
}

static int	parse_score(char score)
{
	if (score == '0')
		return (-110);
	else if (score == '1')
		return (-111);
	else if (score == '2')
		return (-112);
	else if (score == '3')
		return (-113);
	else if (score == '1')
		return (-111);
	else if (score == '4')
		return (-114);
	else if (score == '5')
		return (-115);
	else if (score == '6')
		return (-116);
	else if (score == '7')
		return (-117);
	else if (score == '8')
		return (-118);
	else if (score == '9')
		return (-119);
	else
		return (0);
}

static void	heart_updater(t_game *game)
{
	int		i;

	i = 0;
	if (game->collected)
	{
		while (i < game->collected)
		{
			game->map[0][7 + i] = -123;
			i++;
		}
		if (game->end_game_win)
			game->map[0][7 + i] = -124;
	}
}

static void	score_updater(t_game *game)
{
	char	*moves;

	moves = moves_tostring(game->moves);
	game->map[0][3] = parse_score(moves[0]);
	game->map[0][4] = parse_score(moves[1]);
	game->map[0][5] = parse_score(moves[2]);
	ft_free_ptr((void *)&moves);
}

void	score_update(t_game *game)
{
	score_updater(game);
	heart_updater(game);
}
