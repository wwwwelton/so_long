/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:24:59 by wleite            #+#    #+#             */
/*   Updated: 2021/08/04 05:31:07 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	ch;
	size_t	n;

	n = ft_strlen(s);
	str = (char *)s + n;
	ch = (char)c;
	while (n--)
	{
		if (*str == ch)
			return (str);
		str--;
	}
	if (*str == ch)
		return (str);
	return (NULL);
}
