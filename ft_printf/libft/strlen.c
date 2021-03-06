/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:45:13 by jko               #+#    #+#             */
/*   Updated: 2020/03/21 21:55:37 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == 0)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_wchar_utf8_len(wint_t c)
{
	if (c < 128)
		return (1);
	if (c < 2048)
		return (2);
	if (c < 65536)
		return (3);
	if (c < 2097152)
		return (4);
	return (0);
}

size_t	ft_wstr_utf8_len(const wchar_t *s)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i] != L'\0')
	{
		len += ft_wchar_utf8_len(s[i]);
		i++;
	}
	return (len);
}
