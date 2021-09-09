/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_tostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:34:32 by wleite            #+#    #+#             */
/*   Updated: 2021/08/25 17:38:32 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_char_tostr(unsigned char c)
{
	char	str[2];

	if (c == '\0')
		return (ft_strdup(""));
	str[0] = c;
	str[1] = '\0';
	return (ft_strdup(str));
}
