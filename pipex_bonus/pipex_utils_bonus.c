/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:45:58 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/14 19:57:26 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
		write(2, "Example: ./pipex infile \"cmd1\" \"cmd2\" ... \
				\"cmdn\" outfile\n", 57);
		write(2, "Example: ./pipex here_doc \"cmd1\" \"cmd2\" outfile\n", 48);
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

void	fork_frame(char *argv, char **envp, int outfile, int mode)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_error(ERR);
	pid = fork();
	if (pid == -1)
		ft_error(ERR);
	else if (pid == 0)
	{
		close(fd[0]);
		if (mode == END)
			dup_frame(outfile, STDOUT_FILENO);
		else
			dup_frame(fd[1], STDOUT_FILENO);
		execvision(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup_frame(fd[0], STDIN_FILENO);
	}
}

void	dup_frame(int fd, int std)
{
	if (dup2(fd, std) == -1)
		ft_error(ERR);
	close(fd);
}

int	open_frame(char *file, int mode)
{
	int	fd;

	if (mode == READ)
	{
		fd = open(file, O_RDONLY, 0777);
		if (fd == -1)
			ft_error(ERR);
	}
	else if (mode == WRITE)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
			ft_error(ERR);
	}
	else
	{
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (fd == -1)
			ft_error(ERR);
	}
	return (fd);
}
