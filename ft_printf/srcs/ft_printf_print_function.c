/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_function.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:34:23 by jko               #+#    #+#             */
/*   Updated: 2020/03/15 23:41:27 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_str(char **str, t_format_tag *tag, t_data *data)
{
	size_t	len;

	if (!str || !(*str) || !tag || !data)
		return (ERROR);
	len = ft_strlen(*str);
	if (!apply_alignment(str, &len, tag))
		return (ERROR);
	data->written_len += len;
	return (ft_putstr_fd(*str, 1));
}

int		ft_printf_str(t_format_tag *tag, t_data *data)
{
	char	*str;
	int	result;

	if (!tag || !data || !(str = ft_strdup(va_arg(data->ap, char *))))
		return (ERROR);
	result = print_str(&str, tag, data);
	free(str);
	return (result);
}

int		ft_printf_percent(t_format_tag *tag, t_data *data)
{
	char	*str;
	int	result;

	if (!tag || !data || !(str = malloc(2)))
		return (ERROR);
	str[0] = '%';
	str[1] = NULL_CHAR;
	result = print_str(&str, tag, data);
	free(str);
	return (result);
}

int		ft_printf_char(t_format_tag *tag, t_data *data)
{
	char	*str;
	int	result;

	if (!tag || !data || !(str = malloc(2)))
		return (ERROR);
	str[0] = va_arg(data->ap, int);
	str[1] = NULL_CHAR;
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
	if (!(str = malloc(12)))
		return (ERROR);
	str[0] = '0';
	str[1] = 'x';
	str[11] = NULL_CHAR;
	i = 10;
	while (i > 1)
	{
		str[i] = HEX_DIGIT_STR[addr % 16];
		addr /= 16;
		i--;
	}
	result = print_str(&str, tag, data);
	free(str);
	return (result);
}
