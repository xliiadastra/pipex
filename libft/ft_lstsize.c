/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:08:21 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/10 19:19:16 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*ptr;

	if (!lst)
		return (0);
	count = 1;
	ptr = lst;
	while (lst->next)
	{
		lst = lst->next;
		count++;
	}
	lst = ptr;
	return (count);
}
