/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:01:41 by jko               #+#    #+#             */
/*   Updated: 2020/02/25 20:02:12 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*addr;
	unsigned char	temp;

	i = 0;
	addr = (unsigned char *)b;
	temp = (unsigned char)c;
	while (i < len)
	{
		addr[i] = temp;
		i++;
	}
	return (b);
}
