/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:06:45 by yichoi            #+#    #+#             */
/*   Updated: 2022/04/09 20:50:37 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*saving_line(int fd, char *storage)
{
	char	*buf;
	int		check;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	check = 1;
	while (check != 0 && !gnl_strchr(buf, '\n'))
	{
		check = read(fd, buf, BUFFER_SIZE);
		buf[check] = '\0';
		if (!check)
			break ;
		if (check == -1)
		{
			free(buf);
			return (NULL);
		}
		storage = gnl_strjoin(storage, buf);
	}
	free(buf);
	return (storage);
}

char	*parsing_read(char *storage)
{
	char	*line;
	int		len;
	int		i;

	if (!gnl_strchr(storage, '\n'))
		return (storage);
	i = 0;
	len = gnl_strchr(storage, '\n') - storage + 1;
	line = (char *)malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = storage[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*new_storage(char *storage)
{
	char	*new;
	char	*ptr;

	if (!gnl_strchr(storage, '\n'))
		return (NULL);
	else
	{
		ptr = gnl_strchr(storage, '\n') + 1;
		if (*ptr == '\0')
		{
			free(storage);
			return (NULL);
		}
	}
	new = gnl_strdup(ptr);
	free(storage);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*puts;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	storage = saving_line(fd, storage);
	if (!storage)
		return (NULL);
	puts = parsing_read(storage);
	storage = new_storage(storage);
	return (puts);
}
