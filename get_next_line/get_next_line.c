/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:07:09 by jko               #+#    #+#             */
/*   Updated: 2020/03/10 23:27:17 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct	s_info
{
	char	*remainder;
	int	fd;
	int	is_eof;
}		t_info;

static t_info	info = {0, -1, 0};

int	join(t_info *info, char buf[BUFFER_SIZE + 1])
{
	char	*temp;
	size_t	buf_len;
	size_t	i;
	size_t	j;

	if ((buf_len = ft_strlen(buf)) <= 0)
		return (-1);
	if (info->remainder == 0)
	{
		if ((info->remainder = malloc(buf_len + 1)) == 0)
			return (-1);
		return (ft_strlcpy(info->remainder, buf, buf_len + 1));	
	}
	i = ft_strlen(info->remainder) + buf_len + 1;
	if ((temp = malloc(i)) == 0)
		return (-1);
	j = ft_strlcpy(temp, info->remainder, i);
	ft_strlcpy(temp + j, buf, i);
	free(info->remainder);
	info->remainder = temp;
	return (1);
}

int	return_all(t_info *info, char **line, int read_size)
{
	if (read_size < 0)
		return (-1);
	if (info->remainder != 0)
	{
		*line = info->remainder;
		info->remainder = 0;
		info->is_eof = 1;
		return (0);
	}
	if ((*line = malloc(1)) == 0)
		return (-1);
	(*line)[0] = 0;
	info->is_eof = 1;
	return (0);
}

int	split_and_save(t_info *info, char **line, char *cut_addr)
{
	char	*temp;
	size_t	len;

	if ((*line = malloc(cut_addr - info->remainder)) == 0)
		return (-1);
	ft_strlcpy(*line, info->remainder, cut_addr - info->remainder + 1);
	len = ft_strlen(cut_addr + 1);
	if (len == 0)
	{
		free(info->remainder);
		info->remainder = 0;
		return (1);
	}
	if ((temp = malloc(len + 1)) == 0)
		return (-1);
	ft_strlcpy(temp, cut_addr + 1, len + 1);
	free(info->remainder);
	info->remainder = temp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char	*cut_addr;
	char	buf[BUFFER_SIZE + 1];
	int	read_size;

	if (fd < 0 || line == 0)
		return (-1);
	if (info.fd != fd)
	{
		info.fd = fd;
		info.remainder = 0;
		info.is_eof = 0;
	}
	while ((cut_addr = ft_strchr(info.remainder, '\n')) == 0)
	{
		if ((read_size = read(info.fd, buf, BUFFER_SIZE)) <= 0)
			return (return_all(&info, line, read_size));
		buf[read_size] = 0;
		if (join(&info, buf) == -1)
			return (-1);
	}
	return (split_and_save(&info, line, cut_addr));
}

#include <fcntl.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	int fd;

	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("file open error\n");
		return 0;
	}
	

	char *line;

	int gnl_result;
	while ((gnl_result = get_next_line(fd, &line)) > 0)
	{
		//printf("gnl_result = %d\n", gnl_result);
		printf("%s\n", line);
		free(line);
	}
	//printf("gnl_result = %d\n", gnl_result);
	printf("%s\n", line);
	free(line);
	system("leaks a.out > leaks_result");
	return 0;
}
