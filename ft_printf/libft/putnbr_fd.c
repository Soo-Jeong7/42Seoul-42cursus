/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:48:48 by jko               #+#    #+#             */
/*   Updated: 2020/03/13 00:52:51 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	recur_putnbr(int n, int fd, int *len)
{
	if (n >= 10)
	{
		if (recur_putnbr(n / 10, fd, len) < 0)
			return (-1);
	}
	if (write(fd, &"0123456789"[n % 10], 1) < 1)
		return (-1);
	return (1);
}

int		ft_putnbr_fd(int n, int fd)
{
	int len;

	if (fd < 0)
		return (-1);
	if (n == INT_MIN)
		return (write(fd, INT_MIN_STR, 11));
	len = 0;
	if (n < 0)
	{
		if ((len = write(fd, "-", 1)) < 0)
			return (-1);
		n *= -1;
	}
	if (recur_putnbr(n, fd, &len) < 0)
		return (-1);
	return (len);
}
