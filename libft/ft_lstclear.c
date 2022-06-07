/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:46:10 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/10 19:18:29 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*clear;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		clear = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = NULL;
		if (clear)
			*lst = clear;
	}
}
