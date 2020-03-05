/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:07:09 by jko               #+#    #+#             */
/*   Updated: 2020/03/05 17:51:52 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# define BUFFER_SIZE 4096
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
	info.isEof = FALSE;
}

static void	*ft_memchr(void *addr, int c, size_t size)
{
	size_t i;
	unsigned char	*addr2;
	unsigned char	c2;

	addr2 = (unsigned char *)addr;
	c2 = (unsigned char)c;
	i = 0;
	while (i < size)
	{
		if (addr2[i] == c2)
			return (addr + i);
		i++;
	}
	return (0);
}

static	void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t		i;
	unsigned char	*dst2;
	unsigned char	*src2;


	if (dst == 0 || src == 0)
		return (0);
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}

static bool	add_info_before(char str[], ssize_t read_size)
{
	char	*result;

	if (str == 0)
		return (FALSE);
	if (info.before == 0 || info.before_size == 0)
	{
		info.before = str;
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
	char	*result;
	ssize_t	read_size;

	read_size = read(info.fd, buf, BUFFER_SIZE);
	if (read_size <= 0)
	{
		if (read_size == 0)
			info.isEof = TRUE;
		return (0);
	}
	if (info.before == 0 || !add_info_before(buf, read_size))
		return (0);
	return (info.before);
}

static bool	cut_line(char **line)
{

}

int	get_next_line(int fd, char **line)
{
	if (fd < 0 || line == 0)
		return (-1);
	set_fd_info(fd);
	while (!cut_line(line))
	{
		if (read_fd() == 0)
			return (info.isEof ? 0 : -1);
	}
	return (1);
}
