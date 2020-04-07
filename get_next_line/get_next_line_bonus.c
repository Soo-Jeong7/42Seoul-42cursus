/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:07:09 by jko               #+#    #+#             */
/*   Updated: 2020/04/07 18:05:15 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	join(char **remainder, char buf[BUFFER_SIZE + 1], int read_size)
{
	char	*temp;
	size_t	i;
	size_t	j;

	if (read_size <= 0)
		return (-1);
	if (*remainder == 0)
	{
		if ((*remainder = malloc(read_size + 1)) == 0)
			return (-1);
		return (ft_strlcpy(*remainder, buf, read_size + 1));
	}
	i = ft_strlen(*remainder) + read_size + 1;
	if ((temp = malloc(i)) == 0)
		return (-1);
	j = ft_strlcpy(temp, *remainder, i);
	ft_strlcpy(temp + j, buf, i);
	free(*remainder);
	*remainder = temp;
	return (1);
}

static int	return_all(char **remainder, char **line, int read_size)
{
	if (read_size < 0)
		return (-1);
	if (*remainder != 0)
	{
		*line = *remainder;
		*remainder = 0;
		return (0);
	}
	if ((*line = malloc(1)) == 0)
		return (-1);
	(*line)[0] = 0;
	return (0);
}

static int	split_and_save(char **remainder, char **line, char *cut_addr)
{
	char	*temp;
	size_t	len;

	if ((*line = malloc(cut_addr - *remainder + 1)) == 0)
		return (-1);
	ft_strlcpy(*line, *remainder, cut_addr - *remainder + 1);
	len = ft_strlen(cut_addr + 1);
	if (len == 0)
	{
		free(*remainder);
		*remainder = 0;
		return (1);
	}
	if ((temp = malloc(len + 1)) == 0)
		return (-1);
	ft_strlcpy(temp, cut_addr + 1, len + 1);
	free(*remainder);
	*remainder = temp;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static t_info	info;
	char			*cut_addr;
	int				read_size;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((cut_addr = ft_strchr(info.remainder[fd], '\n')) == 0)
	{
		if ((read_size = read(fd, info.buf, BUFFER_SIZE)) <= 0)
			return (return_all(&(info.remainder[fd]), line, read_size));
		info.buf[read_size] = 0;
		if (join(&info.remainder[fd], info.buf, read_size) == -1)
			return (-1);
	}
	return (split_and_save(&info.remainder[fd], line, cut_addr));
}
