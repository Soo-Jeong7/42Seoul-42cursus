/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:56:40 by jko               #+#    #+#             */
/*   Updated: 2020/03/07 14:57:39 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memchr(void *addr, int c, size_t size)
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

void	*ft_memcpy(void *dst, void *src, size_t n)
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
