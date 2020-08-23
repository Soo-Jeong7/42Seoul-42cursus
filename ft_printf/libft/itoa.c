/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 00:23:17 by jko               #+#    #+#             */
/*   Updated: 2020/03/16 20:57:24 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(long long n)
{
	size_t		len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (++len);
}

char			*ft_itoa(int n)
{
	size_t		len;
	size_t		i;
	long long	n2;
	char		*result;

	len = get_len(n);
	if ((result = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	result[len] = 0;
	i = 0;
	n2 = n < 0 ? (long long)n * -1 : (long long)n;
	while (i < len)
	{
		if (i == len - 1 && n < 0)
		{
			result[0] = '-';
			break ;
		}
		result[len - i - 1] = n2 % 10 + '0';
		n2 /= 10;
		i++;
	}
	return (result);
}