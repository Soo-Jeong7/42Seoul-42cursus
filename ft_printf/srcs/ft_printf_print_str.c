/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:34:23 by jko               #+#    #+#             */
/*   Updated: 2020/03/16 17:40:00 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_str(char **str, t_format_tag *tag, t_data *data)
{
	size_t	len;

	if (!str || !tag || !data)
		return (ERROR);
	if (*str == NULL_POINTER && !(*str = ft_strdup("(null)")))
		return (ERROR);
	len = ft_strlen(*str);
	if (!apply_precision(str, &len, tag)
			|| !apply_alignment(str, &len, tag))
		return (ERROR);
	data->written_len += len;
	return (ft_putstr_fd(*str, 1));
}

int		ft_printf_str(t_format_tag *tag, t_data *data)
{
	char	*str;
	int	result;

	if (!tag || !data)
		return (ERROR);
	if ((str = va_arg(data->ap, char *)) && !(str = ft_strdup(str)))
		return (ERROR);
	result = print_str(&str, tag, data);
	free(str);
	return (result);
}

int		ft_printf_pointer(t_format_tag *tag, t_data *data)
{
	char	*str;
	size_t	addr;
	int	result;
	int	i;
	
	if (!tag || !data)
		return (ERROR);
	addr = va_arg(data->ap, size_t);
	i = !addr ? 4 : 12;
	if (!(str = malloc(i)))
		return (ERROR);
	str[0] = '0';
	str[1] = 'x';
	str[i - 1] = NULL_CHAR;
	i -= 2;
	while (i > 1)
	{
		str[i] = HEX_STR[addr % 16];
		addr /= 16;
		i--;
	}
	result = print_str(&str, tag, data);
	free(str);
	return (result);
}
