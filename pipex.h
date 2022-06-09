/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:57:50 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/09 18:03:25 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "./libft/libft.h"

typedef enum e_error
{
	ERR,
	BAG
}	t_error;

void	child_process(int fd[2], char *argv[], char **envp);
void	parents_process(int fd[2], char *argv[], char **envp);
void	execvision(char *argv, char **envp);
char	*search_path(char *cmd, char **envp);
void	ft_error(int mode);
void	str_isfree(char **str);

#endif
