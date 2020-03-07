/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:07:09 by jko               #+#    #+#             */
/*   Updated: 2020/03/07 14:59:10 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

# define TRUE 1
# define FALSE 0

typedef char bool;

typedef struct	s_fd_info
{
	char	*before;
	size_t	before_size;
	int	fd;
	bool	isEof;
}		t_fd_info;

static t_fd_info info = {0, 0, -1, FALSE};

static void	set_fd_info(int fd)
{
	if (info.fd == fd)
		return ;
	info.fd = fd;
	info.before = 0;
	info.before_size = 0;
	info.isEof = FALSE;
}



static bool	add_info_before(char str[], ssize_t read_size)
{
	char	*result;

	if (str == 0)
		return (FALSE);
	if (info.before == 0 || info.before_size == 0)
	{
		if (!(info.before = (char *)malloc(info.before_size)))
			return (FALSE);
		ft_memcpy(info.before, str, read_size);
		info.before_size = read_size;
		return (TRUE);
	}
	if (!(result = (char *)malloc(info.before_size + read_size)))
		return (FALSE);
	ft_memcpy(result, info.before, info.before_size);
	ft_memcpy(result + info.before_size, str, read_size);
	info.before_size += read_size;
	free(info.before);
	info.before = result;
	return (TRUE);
}

static char	*read_fd(void)
{
	char	buf[BUFFER_SIZE];
	ssize_t	read_size;

	read_size = read(info.fd, buf, BUFFER_SIZE);
	if (read_size < 0)
		return (0);
	if (read_size == 0)
		info.isEof = TRUE;
	if (info.isEof && info.before_size == 0)
		return (0);
	//if (info.before == 0 && !add_info_before(buf, read_size))
	if (!add_info_before(buf, read_size))
		return (0);
	return (info.before);
}

static int	cut_line(char **line)
{
	char	*cut_addr;
	size_t	i;

	if (line == 0)
		return (-1);
	if ((info.before_size == 0
			|| !(cut_addr = ft_memchr(info.before, '\n', info.before_size)))
			&& !info.isEof)
		return (1);
	if (cut_addr == 0 && info.isEof)
	{
		if (!(*line = (char *)malloc(info.before_size + 1)))
			return (-1);
		ft_memcpy(*line, info.before, info.before_size);
		(*line)[info.before_size] = 0;
		return (0);
	}
	i = cut_addr - info.before + 1;
	if (i == 1 && info.before[0] == 0)
		return (1);
	if (!(*line = (char *)malloc(sizeof(char) * i)))
		return (-1);
	ft_memcpy(*line, info.before, i);
	(*line)[i - 1] = 0;
	info.before_size -= i;
	ft_memcpy(info.before, info.before + i, info.before_size);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int cut_result;

	if (fd < 0 || line == 0)
		return (-1);
	set_fd_info(fd);
	if (info.isEof && info.before_size == 0)
		return (0);
	while ((cut_result = cut_line(line)) > 0)
	{
		if (read_fd() == 0)
		{
			return (info.isEof ? 0 : -1);
		}
	}
	if (cut_result < 0)
		return (-1);
	if (info.isEof && info.before_size == 0)
		return (0);
	return (1);
}


#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	//int fd = open("1.txt", O_RDONLY);
	int fd = open("test_text", O_RDONLY);
	if (fd < 0)
	{
		printf("file open error\n");
		return 0;
	}
	char *line;

	while (get_next_line(fd, &line) > 0)
	{
		printf("main print = %s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	
	system("leaks a.out > leaks_result");
	return 0;
}
