/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putwstr_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:19:50 by jko               #+#    #+#             */
/*   Updated: 2020/03/21 21:11:00 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putwstr_fd(wchar_t *s, int fd)
{
	int	len;
	int	i;
	int	temp;

	if (s == 0 || fd < 0)
		return (ERROR);
	len = 0;
	i = 0;
	while (s[i])
	{
		if ((temp = ft_putwchar_fd(s[i], fd)) < 0)
			return (ERROR);
		len += temp;
		i++;
	}
	return (len);
}
