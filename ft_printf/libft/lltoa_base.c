/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lltoa_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 20:56:59 by jko               #+#    #+#             */
/*   Updated: 2020/03/16 23:00:57 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_number_len(long long n, long long base_len)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n >= base_len)
	{
		len++;
		n /= base_len;
	}
	return (++len);
}

static char		*make_num_str(
		long long n, size_t len,
		char *base, size_t base_len)
{
	size_t		i;
	char		*result;
	long long	n2;

	if ((result = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	result[len] = 0;
	i = 0;
	n2 = n >= 0 ? n : (n * (-1));
	while (i < len)
	{
		if (i + 1 == len && n < 0)
		{
			result[0] = '-';
			break ;
		}
		result[len - i - 1] = base[n2 % base_len];
		n2 /= base_len;
		i++;
	}
	return (result);
}

char			*ft_lltoa_base(long long n, char *base)
{
	size_t	len;
	size_t	base_len;

	if (base == 0)
		base = DIGIT_STR;
	if (n == LLONG_MIN && ft_strncmp(base, DIGIT_STR, ft_strlen(DIGIT_STR)))
		return (LLONG_MIN_STR);
	if ((base_len = ft_strlen(base)) < 2)
		return (0);
	len = get_number_len(n, base_len);
	return (make_num_str(n, len, base, base_len));
}