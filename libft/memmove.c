/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 00:47:48 by jko               #+#    #+#             */
/*   Updated: 2020/04/07 17:13:47 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;

	if (dst == src || len == 0)
		return (dst);
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;	
	i = 0;
	if (dst < src)
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	else
		while (i < len)
		{
			dst2[len - i - 1] = src2[len - i - 1];
			i++;
		}
	return (dst);
}
