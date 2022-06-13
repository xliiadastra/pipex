/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:51:57 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/13 23:58:02 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# define BUFFER_SIZE 1024

char	*get_next_line(int fd);
char	*saving_line(int fd, char *storage);
char	*parsing_read(char *storage);
char	*new_storage(char *storage);
char	*gnl_strchr(char *str, int c);
char	*gnl_str_catcpy(char *join, char *dst, char *src);
char	*gnl_strdup(char *str);
char	*gnl_strjoin(char *dst, char *src);

#endif
