/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:45:40 by jko               #+#    #+#             */
/*   Updated: 2020/02/26 21:38:26 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*s2;
	char	c2;

	s2 = (char *)s;
	c2 = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s2[i] == c2)
			return (s2 + i);
		i--;
	}
	if (s2[i] == c2)
		return (s2);
	return (0);
}
