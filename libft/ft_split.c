/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:09:55 by wleite            #+#    #+#             */
/*   Updated: 2021/08/07 13:16:12 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	strelem(char *str, char delim)
{
	size_t	i;

	if (!*str)
		return (0);
	i = 1;
	while (*str)
	{
		if (*str == delim)
			i++;
		str++;
	}
	return (i);
}

static char	*strsubsep(char *stringp, char sub, char delim)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (!stringp)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(stringp);
	while (stringp[i] && i < len)
	{
		if (stringp[i] != delim)
			stringp[j++] = stringp[i];
		if (stringp[i] == delim && stringp[i + 1] != delim)
			if (j > 0 && i < len - 1)
				stringp[j++] = sub;
		i++;
	}
	stringp[j] = '\0';
	return (stringp);
}

static void	pfree(char **ptr, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
	{
		free(ptr[i]);
		ptr[i] = NULL;
	}
	free(ptr);
	ptr = NULL;
}

static void	copyelem(char **save_ptr, char *str, size_t size, char delim)
{
	size_t	i;

	str = strsubsep(str, '\0', delim);
	i = -1;
	while (++i < (size - 1))
	{
		save_ptr[i] = ft_strdup(str);
		if (!save_ptr[i])
		{
			pfree(save_ptr, i);
			return ;
		}
		str += ft_strlen(str) + 1;
	}
	save_ptr[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	char	*str;
	size_t	size;

	if (!s)
		return (NULL);
	str = strsubsep(ft_strdup(s), c, c);
	if (!str)
		return (NULL);
	size = strelem(str, c) + 1;
	ptr = (char **)malloc(sizeof(char *) * size);
	if (!ptr)
		return (NULL);
	copyelem(ptr, str, size, c);
	free(str);
	return (ptr);
}
