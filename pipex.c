/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:15:40 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/04 21:04:19 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[], char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		ft_error(BAG);
	if (pipe(fd) == -1)
		ft_error(ERR);
	pid = fork();
	if (pid == -1)
		ft_error(ERR);
	else if (pid == 0)
		;
	else
	{
	}
	//close();
	//close();

	return (0);
}
