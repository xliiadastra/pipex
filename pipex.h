/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:57:50 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/04 20:26:58 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdring.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef enum e_error
{
	ERR,
	BAG
}	t_error;

#endif
