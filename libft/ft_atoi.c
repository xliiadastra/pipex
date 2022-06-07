/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:58:20 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/07 21:04:34 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_atoi(const char *str)
{
	char				sign;
	unsigned long long	result;

	result = 0;
	sign = 1;
	while (is_space(*str) && *str)
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while ((*str >= '0' && *str <= '9') && *str)
	{
		result = (result * 10) + (long long)(*str - '0');
		str++;
	}
	if (result > 9223372036854775807ULL && sign == 1)
		return (-1);
	else if (result > 9223372036854775808ULL && sign == -1)
		return (0);
	else
		return ((int)((long long)sign * result));
}
