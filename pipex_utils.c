/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:45:58 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/07 21:57:06 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int mode)
{
	if (mode == ERR)
	{
		perror("Error");
		exit(1);
	}
	if (mode == BAG)
	{
		write(2, "Error: Bad Arguments\n", 21);
		write(2, "Example: ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 46);
		exit(1);
	}
}

void	str_isfree(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
}
