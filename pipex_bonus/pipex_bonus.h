/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:42:19 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/13 23:54:37 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "./get_next_line.h"
# include "../libft/libft.h"

typedef enum e_error
{
	ERR,
	BAG
}	t_error;

typedef enum e_open
{
	READ,
	WRITE,
	APPEND
}	t_open;

void	ft_error(int mode);
void	str_isfree(char **str);
void	fork_frame(char *argv, char **envp, int ac, int i, int outfile);
int		open_frame(char *file, int mode);
void	dup_frame(int fd, int std);

void	here_doc(int fd, char *limiter, int argc);

void	execvision(char *argv, char **envp);
char	*search_path(char *cmd, char **envp);

#endif
