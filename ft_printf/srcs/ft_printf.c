/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:23:58 by jko               #+#    #+#             */
/*   Updated: 2020/03/16 21:39:13 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool		apply_alignment(char **str, size_t *len, t_format_tag *tag)
{
	char	*temp;
	bool	check;

	if (!str || !*str || !tag)
		return (false);
	if (*len >= (size_t)tag->width)
		return (true);
	if (!(temp = malloc(tag->width + 1)))
		return (false);
	if (tag->left_align)
	{
		ft_strlcpy(temp, *str, *len + 1);
		ft_memset(temp + *len, ' ', tag->width - *len);
		temp[tag->width] = NULL_CHAR;
	}
	else
	{
		check = tag->fill_zero && tag->precision < 0;
		ft_memset(temp, check ? '0' : ' ', tag->width - *len);
		ft_strlcpy(temp + tag->width - *len, *str, *len + 1);
	}
	free(*str);
	*str = temp;
	*len = tag->width;
	return (true);
}

bool		apply_precision(char **str, size_t *len, t_format_tag *tag)
{
	char	*temp;

	if (!str || !*str || !tag)
		return (false);
	if (tag->precision < 0)
		return (true);
	if (tag->specifier == 's')
	{
		if (*len > (size_t)tag->precision)
		{
			if (!(temp = ft_strndup(*str, tag->precision)))
				return (false);
			free(*str);
			*str = temp;
			*len = tag->precision;
		}
		return (true);
	}
	
	if (ft_strchr("diuxX", tag->specifier))
	{
		if (*len < (size_t)tag->precision)
		{
			if (!(temp = malloc(tag->precision + 1)))
				return (false);
			ft_memset(temp, '0', tag->precision - *len);
			ft_strlcpy(temp + tag->precision - *len, *str, *len + 1);
			free(*str);
			*str = temp;
			*len = tag->precision;
		}
		else if (tag->precision == 0)
		{
			if (!(temp = ft_strdup("")))
				return (false);
			free(*str);
			*str = temp;
			*len = tag->precision;
		}
		return (true);
	}

	return (true);
}

bool		apply_flag_sharp(
		char **str, size_t *len,
		t_format_tag *tag,
		bool is_zero)
{
	char	*temp;

	if (!str || !*str || !tag)
		return (false);
	if (!tag->sharp)
		return (true);
	if (ft_strchr("xX", tag->specifier) && !is_zero)
	{
		if (!(temp = malloc(*len + 3)))
			return (false);
		ft_strlcpy(temp, tag->specifier == 'x' ? "0x" : "0X", 3);
		ft_strlcpy(temp + 2, *str, *len + 1);
		free(*str);
		*str = temp;
		*len += 2;
		return (true);
	}
	return (true);
}

static int	ft_printf_format(t_format_tag *tag, t_data *data)
{
	if (tag == 0 || data == 0)
		return (ERROR);
	if (tag->specifier == 'c')
		return (ft_printf_char(tag, data));
	else if (tag->specifier == 's')
		return (ft_printf_str(tag, data));
	else if (tag->specifier == 'p')
		return (ft_printf_pointer(tag, data));
	else if (tag->specifier == '%')
		return (ft_printf_percent(tag, data));
	else if (tag->specifier == 'u')
		return (ft_printf_unsigned_number(tag, data, DIGIT_STR));
	else if (tag->specifier == 'x')
		return (ft_printf_unsigned_number(tag, data, HEX_STR));
	else if (tag->specifier == 'X')
		return (ft_printf_unsigned_number(tag, data, HEX_STR_UPPER));
	else if (tag->specifier == 'd' || tag->specifier == 'i')
		return (ft_printf_signed_number(tag, data));
	
	return (ERROR);
}

static bool	ft_printf_print_text(t_data *data, size_t write_len)
{
	int len;

	if (!data || write_len < 0)
		return (false);
	len = write(1, data->format, write_len);
	if (len < 0)
		return (false);
	data->written_len += len;
	data->format += len;
	return (true);
}

static int	ft_printf_print(t_data *data)
{
	char		*tag_start;
	t_format_tag	*tag;
	int		result;

	while ((tag_start = ft_strchr(data->format, '%')) != 0)
	{
		if (!ft_printf_print_text(data, tag_start - data->format)
				|| !(tag = ft_printf_get_tag(tag_start, data)))
			return (ERROR);
		result = ft_printf_format(tag, data);
		free(tag);
		if (result == ERROR)
			return (ERROR);
	}
	if (!ft_printf_print_text(data, ft_strlen(data->format)))
		return (ERROR);
	return (data->written_len);
}

int		ft_printf(const char *format, ...)
{
	t_data	data;
	
	if (format == 0)
		return (ERROR);
	va_start(data.ap, format);
	data.format = format;
	data.written_len = 0;
	if (ft_printf_print(&data) == ERROR)
		data.written_len = ERROR;
	va_end(data.ap);
	return (data.written_len);
}
