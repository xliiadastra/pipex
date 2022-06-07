/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:03:24 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/06 20:19:56 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;
	size_t				i;

	if (!dst && !src)
		return (dst);
	ptr_dst = (unsigned char *)dst;
	ptr_src = (const unsigned char *)src;
	if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			ptr_dst[i - 1] = ptr_src[i - 1];
			i--;
		}
		return ((void *)dst);
	}
	i = 0;
	while (i < len)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return ((void *)dst);
}
