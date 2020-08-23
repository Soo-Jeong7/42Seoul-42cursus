/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putendl_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:43:49 by jko               #+#    #+#             */
/*   Updated: 2020/03/13 00:39:00 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	size_t	len;
	int		result;

	if (s == 0 || fd < 0)
		return (-1);
	len = ft_strlen(s);
	s[len] = '\n';
	result = write(fd, s, len + 1);
	s[len] = 0;
	return (result);
}
