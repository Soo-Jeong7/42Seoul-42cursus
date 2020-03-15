/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:23:58 by jko               #+#    #+#             */
/*   Updated: 2020/03/15 23:42:52 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool		apply_alignment(char **str, size_t *len, t_format_tag *tag)
{
	char	*temp;

	if (str == NULL_POINTER || *str == NULL_POINTER || tag == NULL_POINTER)
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
		ft_memset(temp, tag->fill_zero ? '0' : ' ', tag->width - *len);
		ft_strlcpy(temp + tag->width - *len, *str, *len + 1);
	}
	free(*str);
	*str = temp;
	*len = tag->width;
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
