/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:21:33 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/14 00:14:59 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(int fd, char *limiter, int argc)
{
	char	*ptr;

	if (argc < 6)
		ft_error(BAG);
	while (1)
	{
		ptr = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(ptr, limiter, ft_strlen(limiter)))
		{
			free(ptr);
			break ;
		}
		write(fd, ptr, ft_strlen(ptr));
		free(ptr);
	}
	close(fd);
	fd = open("infile_temp", O_RDONLY, 0777);
}

void	execvision(char *argv, char **envp)
{
	char	**cmd;
	char	*program_path;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		ft_error(ERR);
	program_path = search_path(cmd[0], envp);
	if (execve(program_path, cmd, envp) == -1)
		ft_error(ERR);
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
