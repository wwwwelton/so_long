/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:25:03 by wleite            #+#    #+#             */
/*   Updated: 2021/07/27 19:25:03 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	litsize;

	litsize = ft_strlen(little);
	if (!litsize)
		return ((char *)big);
	while (*big && litsize <= len--)
	{
		if (!ft_strncmp(big, little, litsize))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
