/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_unsigned_num.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:28:46 by jko               #+#    #+#             */
/*   Updated: 2020/04/07 18:16:19 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	move_0x(char **str, bool is_upper)
{
	char *x_addr;

	if (!str || !*str || !(x_addr = ft_strchrset(*str, "xX")))
		return (false);
	*(x_addr - 1) = (*str)[0];
	(*str)[0] = '0';
	*x_addr = (*str)[1];
	(*str)[1] = is_upper ? 'X' : 'x';
	return (true);
}

static int	print_unsigned_num(
		char **str, t_format_tag *tag,
		t_data *data, bool is_zero)
{
	size_t	len;

	if (!str || !*str || !tag || !data)
		return (ERROR);
	len = ft_strlen(*str);
	if (!apply_precision(str, &len, tag)
			|| !apply_flag_sharp(str, &len, tag, is_zero)
			|| !apply_alignment(str, &len, tag))
		return (ERROR);
	if (ft_strchr("xX", tag->specifier)
			&& tag->sharp && tag->precision == -1
			&& tag->fill_zero && !is_zero)
		if (!move_0x(str, tag->specifier == 'X'))
			return (ERROR);
	data->written_len += len;
	return (ft_putstr_fd(*str, 1));
}

int			ft_printf_unsigned_number(t_format_tag *tag, t_data *data, char *base)
{
	char				*str;
	unsigned long long	arg;
	int					result;

	if (!tag || !data)
		return (ERROR);
	arg = va_arg(data->ap, unsigned long long);
	if (tag->length == TAG_LENGTH_H)
		str = ft_ulltoa_base((unsigned short)arg, base);
	else if (tag->length == TAG_LENGTH_HH)
		str = ft_ulltoa_base((unsigned char)arg, base);
	else if (tag->length == TAG_LENGTH_L)
		str = ft_ulltoa_base((unsigned long)arg, base);
	else if (tag->length == TAG_LENGTH_LL)
		str = ft_ulltoa_base(arg, base);
	else
		str = ft_ulltoa_base((unsigned int)arg, base);
	if (!str)
		return (ERROR);
	result = print_unsigned_num(&str, tag, data, arg == 0);
	free(str);
	return (result);
}

int			ft_printf_pointer(t_format_tag *tag, t_data *data)
{
	char	*str;
	size_t	addr;
	int		result;

	if (!tag || !data)
		return (ERROR);
	addr = va_arg(data->ap, size_t);
	tag->sharp = true;
	str = ft_ulltoa_base((unsigned long)addr, HEX_STR);
	result = print_unsigned_num(&str, tag, data, false);
	free(str);
	return (result);
}
