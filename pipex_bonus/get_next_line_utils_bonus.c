/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:40:47 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/13 23:58:16 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}

char	*gnl_str_catcpy(char *join, char *dst, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[i])
	{
		join[i] = dst[i];
		i++;
	}
	while (src[j])
	{
		join[i] = src[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

char	*gnl_strdup(char *str)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!copy)
		return (0);
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*gnl_strjoin(char *dst, char *src)
{
	char	*join;

	if (!dst && !src)
		return (0);
	else if (!dst)
		return (gnl_strdup(src));
	else if (!src)
		return (gnl_strdup(dst));
	join = (char *)malloc(sizeof(char) * (ft_strlen(dst) + ft_strlen(src) + 1));
	if (!join)
		return (0);
	gnl_str_catcpy(join, dst, src);
	free(dst);
	return (join);
}
