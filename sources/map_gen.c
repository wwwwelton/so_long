/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 00:43:20 by wleite            #+#    #+#             */
/*   Updated: 2021/09/13 23:06:53 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**map_gen(char *path_to_file)
{
	char	**result;
	char	*holder;
	char	*old_address;
	char	*map;
	int		fd;

	fd = open(path_to_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = ft_strdup("");
	while (1)
	{
		holder = get_next_line(fd);
		if (!holder)
			break ;
		old_address = map;
		map = ft_strjoin(old_address, holder);
		ft_free_ptr((void *)&old_address);
		ft_free_ptr((void *)&holder);
	}
	result = ft_split(map, '\n');
	ft_free_ptr((void *)&map);
	close(fd);
	return (result);
}
