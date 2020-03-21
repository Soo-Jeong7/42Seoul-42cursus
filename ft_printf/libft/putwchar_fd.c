/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putwchar_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:17:49 by jko               #+#    #+#             */
/*   Updated: 2020/03/21 21:23:52 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_utf8_2byte(wint_t c, int fd)
{
	unsigned char buf[2];

	buf[0] = (c >> 6) | 0b11000000;
	buf[1] = (c & 0b111111) | 0b10000000;
	return (write(fd, buf, 2));
}

static int	print_utf8_3byte(wint_t c, int fd)
{
	unsigned char buf[3];

	buf[0] = (c >> 12) | 0b11100000;
	buf[1] = ((c >> 6) & 0b111111) | 0b10000000;
	buf[2] = (c & 0b111111) | 0b10000000;
	return (write(fd, buf, 3));
}

static int	print_utf8_4byte(wint_t c, int fd)
{
	unsigned char buf[4];

	buf[0] = (c >> 18) | 0b11110000;
	buf[1] = ((c >> 12) & 0b111111) | 0b10000000;
	buf[2] = ((c >> 6) & 0b111111) | 0b10000000;
	buf[3] = (c & 0b111111) | 0b10000000;
	return (write(fd, buf, 4));
}

int	ft_putwchar_fd(wint_t c, int fd)
{
	if (fd < 0)
		return (ERROR);
	if (c < 128)
		return (write(fd, &c, 1));
	if (c < 2048)
		return (print_utf8_2byte(c, fd));
	if (c < 65536)
		return (print_utf8_3byte(c, fd));
	if (c < 2097152)
		return (print_utf8_4byte(c, fd));
	return (ERROR);
}
