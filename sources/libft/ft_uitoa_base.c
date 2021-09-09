/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:59:04 by wleite            #+#    #+#             */
/*   Updated: 2021/09/08 17:11:21 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	strrev(char *str)
{
	char	temp;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(str) - 1;
	if (str[start] == '-')
		start++;
	while (str[start] && start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

static size_t	ft_count_digits(size_t n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa_base(size_t n, const char *base)
{
	char	*str;
	size_t	base_len;
	size_t	i;

	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(sizeof(char) * (ft_count_digits(n) + 1));
	if (!str)
		return (NULL);
	base_len = ft_strlen(base);
	i = 0;
	if (n < 0)
	{
		n = -n;
		str[i++] = '-';
	}
	while (n)
	{
		str[i++] = base[n % base_len];
		n = n / base_len;
	}
	str[i] = '\0';
	strrev(str);
	return (str);
}
