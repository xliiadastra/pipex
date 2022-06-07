/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:21:33 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/07 22:40:48 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int fd[2], char *argv[], char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (dup2(infile, STDIN_FILENO) == -1)
		ft_error(ERR);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error(ERR);
	close(fd[0]);
	execvision(argv[2], envp);
}

void	parents_process(int fd[2], char *argv[], char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error(ERR);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		ft_error(ERR);
	close(fd[1]);
	execvision(argv[3], envp);
}

void	execvision(char *argv, char **envp)
{
	char	**cmd;
	char	*progrem_path;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		ft_error(ERR);
	progrem_path = search_path(cmd[0], envp);
	if (execve(progrem_path, cmd, envp) == -1)
		ft_error(ERR);
	str_isfree(cmd);
}

char	*search_path(char *cmd, char **envp)
{
	char	**other_paths;
	char	*path;
	char	*cmd_path;
	int		i;

	i = -1;
	path = ft_strjoin("/", cmd);
	if (!path)
		ft_error(ERR);
	while (!ft_strnstr(envp[++i], "PATH", 4))
		;
	other_paths = ft_split(envp[i] + 5, ':');
	if (!other_paths)
		ft_error(ERR);
	i = -1;
	while (other_paths[++i])
	{
		cmd_path = ft_strjoin(other_paths[i], path);
		if (!access(cmd_path, X_OK))
			break ;
		free(cmd_path);
	}
	str_isfree(other_paths);
	free(path);
	return (cmd_path);
}
