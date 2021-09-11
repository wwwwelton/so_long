/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:24:48 by wleite            #+#    #+#             */
/*   Updated: 2021/08/04 05:19:01 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strnlen(const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (s[i] && i < n)
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	len;

	if (!dst || !src)
		return (0);
	srclen = ft_strlen(src);
	if (dstsize)
	{
		len = strnlen(src, dstsize - 1);
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (srclen);
}
