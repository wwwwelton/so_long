/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 02:26:04 by wleite            #+#    #+#             */
/*   Updated: 2021/08/07 20:18:12 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp_element;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp_element = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp_element;
	}
	*lst = NULL;
}
