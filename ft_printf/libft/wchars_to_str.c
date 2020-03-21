/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchars_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:17:49 by jko               #+#    #+#             */
/*   Updated: 2020/03/21 21:58:03 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_utf8_2byte(char *dst, wint_t c)
{
	dst[0] = (c >> 6) | 0b11000000;
	dst[1] = (c & 0b111111) | 0b10000000;
	return (2);
}

static int	print_utf8_3byte(char *dst, wint_t c)
{
	dst[0] = (c >> 12) | 0b11100000;
	dst[1] = ((c >> 6) & 0b111111) | 0b10000000;
	dst[2] = (c & 0b111111) | 0b10000000;
	return (3);
}

static int	print_utf8_4byte(char *dst, wint_t c)
{
	dst[0] = (c >> 18) | 0b11110000;
	dst[1] = ((c >> 12) & 0b111111) | 0b10000000;
	dst[2] = ((c >> 6) & 0b111111) | 0b10000000;
	dst[3] = (c & 0b111111) | 0b10000000;
	return (4);
}

static int	wchar_to_str(char *dst, wint_t c)
{
	if (c < 128)
	{
		dst[0] = c;
		return (1);
	}
	if (c < 2048)
		return (print_utf8_2byte(dst, c));
	if (c < 65536)
		return (print_utf8_3byte(dst, c));
	if (c < 2097152)
		return (print_utf8_4byte(dst, c));
	return (ERROR);
}

char		*ft_wchars_to_str(const wchar_t *ws)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;
	int	temp;

	if (!ws)
		return (NULL_POINTER);
	len = ft_wstr_utf8_len(ws);
	if (!(str = malloc(len + 1)))
		return (NULL_POINTER);
	i = 0;
	j = 0;
	while (ws[i] != L'\0')
	{
		if ((temp = wchar_to_str(str + j, ws[i])) == ERROR)
		{
			free(str);
			return (NULL_POINTER);
		}
		j += temp;
		i++;
	}
	str[len] = NULL_CHAR;
	return (str);
}
