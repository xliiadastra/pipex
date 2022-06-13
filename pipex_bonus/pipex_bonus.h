/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:42:19 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/13 17:45:21 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "pipex.h"

typedef enum e_open
{
	READ,
	WRITE,
	APPEND
}	t_open;

void	fork_frame(char *argv, char **envp);
void	open_fream(char *file, int mode);
void	dup_fream(int fd, int std);

#endif
