/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:24:28 by wleite            #+#    #+#             */
/*   Updated: 2021/08/04 04:48:46 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*memrcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	if ((!dst && !src) || !len)
		return (dst);
	ptr_dest = (unsigned char *)dst + len - 1;
	ptr_src = (unsigned char *)src + len - 1;
	while (len--)
		*ptr_dest-- = *ptr_src--;
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if ((!dst && !src) || !len)
		return (dst);
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	else
		return (memrcpy(dst, src, len));
}
