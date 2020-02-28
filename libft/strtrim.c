/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 11:29:51 by jko               #+#    #+#             */
/*   Updated: 2020/02/28 13:04:37 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_back_index(const char *s1, const char *set, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && ft_strchr(set, s1[len - i - 1]))
		i++;
	return (len - i);
}

static size_t	get_front_index(const char *s1, const char *set, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	back;
	size_t	len;
	char	*result;

	if (s1 == 0 || set == 0)
		return (0);
	len = ft_strlen(s1);
	front = get_front_index(s1, set, len);
	back = get_back_index(s1, set, len);
	if ((result = (char *)malloc(sizeof(char) * (back - front + 1))) == 0)
		return (0);
	ft_strlcpy(result, s1 + front, back - front + 1);
	return (result);
}
