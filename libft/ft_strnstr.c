/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:20:47 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/06 20:04:36 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*ptr;
	size_t		i;
	size_t		j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		ptr = needle;
		if (haystack[i] == *ptr)
		{
			j = i;
			while (haystack[j] == *ptr && haystack[j] && j < len && *ptr)
			{
				ptr++;
				j++;
			}
			if (*ptr == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
