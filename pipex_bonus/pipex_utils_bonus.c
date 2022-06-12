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

void	fork_(int )
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error(ERR);
	else if (pid == 0)
}

void	dup_(int fd, int std)
{

	if (dup2(fd, std) == -1)
		ft_error(ERR);
	close(fd);
}

void	open_file(char *file, int mode)
{
	int	fd;

	if (mode == READ)
	{
		fd = open(file, O_RDONLY, 0777);
		if (fd < 0)
			ft_error(ERR);
	}
	else if (mode == WRITE)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd < 0)
			ft_error(ERR);
	}
	else
	{
		fd = open(file, O_APPEND, 0777);
		if (fd < 0)
			ft_error(ERR);
	}
}
