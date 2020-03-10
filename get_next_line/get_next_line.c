/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:07:09 by jko               #+#    #+#             */
/*   Updated: 2020/03/11 02:18:38 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*info[OPEN_MAX];

static int	join(int fd, char buf[BUFFER_SIZE + 1], int read_size)
{
	char	*temp;
	size_t	i;
	size_t	j;

	if (read_size <= 0)
		return (-1);
	if (info[fd] == 0)
	{
		if ((info[fd] = malloc(read_size + 1)) == 0)
			return (-1);
		return (ft_strlcpy(info[fd], buf, read_size + 1));	
	}
	i = ft_strlen(info[fd]) + read_size + 1;
	if ((temp = malloc(i)) == 0)
		return (-1);
	j = ft_strlcpy(temp, info[fd], i);
	ft_strlcpy(temp + j, buf, i);
	free(info[fd]);
	info[fd] = temp;
	return (1);
}

static int	return_all(int fd, char **line, int read_size)
{
	if (read_size < 0)
		return (-1);
	if (info[fd] != 0)
	{
		*line = info[fd];
		info[fd] = 0;
		return (0);
	}
	if ((*line = malloc(1)) == 0)
		return (-1);
	(*line)[0] = 0;
	return (0);
}

static int	split_and_save(int fd, char **line, char *cut_addr)
{
	char	*temp;
	size_t	len;

	if ((*line = malloc(cut_addr - info[fd] + 1)) == 0)
		return (-1);
	ft_strlcpy(*line, info[fd], cut_addr - info[fd] + 1);
	len = ft_strlen(cut_addr + 1);
	if (len == 0)
	{
		free(info[fd]);
		info[fd] = 0;
		return (1);
	}
	if ((temp = malloc(len + 1)) == 0)
		return (-1);
	ft_strlcpy(temp, cut_addr + 1, len + 1);
	free(info[fd]);
	info[fd] = temp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char	*cut_addr;
	char	buf[BUFFER_SIZE + 1];
	int	read_size;

	if (fd < 0 || line == 0)
		return (-1);
	while ((cut_addr = ft_strchr(info[fd], '\n')) == 0)
	{
		if ((read_size = read(fd, buf, BUFFER_SIZE)) <= 0)
			return (return_all(fd, line, read_size));
		buf[read_size] = 0;
		if (join(fd, buf, read_size) == -1)
			return (-1);
	}
	return (split_and_save(fd, line, cut_addr));
}
