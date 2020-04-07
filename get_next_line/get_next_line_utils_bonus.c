/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:56:40 by jko               #+#    #+#             */
/*   Updated: 2020/04/07 18:05:50 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	size_t 			i;
	unsigned char	c2;

	if (str == 0)
		return (0);
	c2 = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == c2)
			return (str + i);
		i++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (dst == 0 || dstsize == 0)
		return (src_len);
	i = 0;
	while (i < src_len && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (src_len);
}

size_t	ft_strlen(const char *s)
{
	size_t len;

	if (s == 0)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

