/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulltoa_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 20:51:59 by jko               #+#    #+#             */
/*   Updated: 2020/08/24 00:01:43 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_unsigned_number_len(
				unsigned long long n, unsigned long long base_len)
{
	size_t			len;

	len = 0;
	while (n >= base_len)
	{
		len++;
		n /= base_len;
	}
	return (++len);
}

char			*ft_ulltoa_base(unsigned long long n, char *base)
{
	size_t	len;
	size_t	base_len;
	size_t	i;
	char	*result;

	if (base == 0)
		base = "0123456789";
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	len = get_unsigned_number_len(n, base_len);
	if ((result = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	result[len] = 0;
	i = 0;
	while (i < len)
	{
		result[len - i - 1] = base[n % base_len];
		n /= base_len;
		i++;
	}
	return (result);
}
