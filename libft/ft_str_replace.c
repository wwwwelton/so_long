/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:03:55 by wleite            #+#    #+#             */
/*   Updated: 2021/09/08 17:10:20 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_replace(const char *str,
	const char *old_word, const char *new_word)
{
	char	*new_str;
	char	*ptr;
	int		total_size;
	int		i;

	if (!str || !old_word || !new_word)
		return (NULL);
	total_size = ft_strlen(str) - ft_strlen(old_word) + ft_strlen(new_word) + 1;
	new_str = (char *)ft_calloc(total_size, sizeof(char *));
	if (!new_str)
		return (NULL);
	i = 0;
	ptr = ft_strnstr(str, old_word, ft_strlen(str));
	if (ptr)
	{
		ft_strlcpy(new_str, str, (ptr - str) + 1);
		ft_strlcat(new_str, new_word, total_size);
		i = (ptr - str) + ft_strlen(old_word);
	}
	ft_strlcat(new_str, str + i, total_size);
	return (new_str);
}
