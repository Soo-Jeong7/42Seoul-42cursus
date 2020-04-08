/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 22:19:41 by jko               #+#    #+#             */
/*   Updated: 2020/04/07 17:14:44 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (ss1 == 0 && ss2 == 0)
		return (0);
	else if (ss1 == 0 || ss2 == 0)
		return (ss1 == 0 ? -1 : 1);
	i = 0;
	while (i < n && ss1[i] && ss2[i])
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (ss1[i] - ss2[i]);
}
