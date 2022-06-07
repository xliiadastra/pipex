/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:41:58 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/09 18:52:09 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	valid(int n, int fd)
{
	char	*min_int;

	if (fd < 0)
		return (0);
	min_int = "-2147483648";
	if (n == -2147483648)
	{
		write(fd, min_int, 11);
		return (0);
	}
	return (1);
}

static void	itoa_fd(int n, int *len, int fd)
{
	char	ptr[10];
	int		n_len;

	n_len = *len;
	while (n)
	{
		ptr[n_len] = n % 10 + '0';
		n /= 10;
		n_len--;
	}
	while (++n_len <= 9)
		write(fd, &ptr[n_len], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		len;

	if (!valid(n, fd))
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	len = 9;
	itoa_fd(n, &len, fd);
}
