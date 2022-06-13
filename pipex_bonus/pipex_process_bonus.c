/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:21:33 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/13 22:48:36 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(int i, char *c, int r)
{
	(void)i;
	(void)c;
	(void)r;
	exit(1);
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
