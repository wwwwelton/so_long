/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:24:24 by wleite            #+#    #+#             */
/*   Updated: 2021/08/04 04:44:51 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	if ((!dst && !src) || !len)
		return (dst);
	ptr_dest = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	while (len--)
		*ptr_dest++ = *ptr_src++;
	return (dst);
}
