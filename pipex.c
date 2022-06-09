/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:15:40 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/09 23:24:00 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;

	if (argc != 5)
		ft_error(BAG);
	if (pipe(fd) == -1)
		ft_error(ERR);
	pid = fork();
	if (pid == -1)
		ft_error(ERR);
	else if (pid == 0)
		child_process(fd, argv, envp);
	pid2 = fork();
	if (pid2 == -1)
		ft_error(ERR);
	else if (pid2 == 0)
		parents_process(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(-1, 0, 0);
	waitpid(-1, 0, 0);
	return (0);
}
