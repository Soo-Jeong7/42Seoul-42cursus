/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strndup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 22:19:44 by jko               #+#    #+#             */
/*   Updated: 2020/03/12 22:20:21 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*result;
	size_t	len;
	size_t	i;

	if (n <= 0 || !(len = ft_strlen(str)))
		return (ft_strdup(""));
	len = n < len ? n : len;
	if (!(result = malloc(len + 1)))
		return (0);
	i = 0;
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = 0;
	return (result);
}
