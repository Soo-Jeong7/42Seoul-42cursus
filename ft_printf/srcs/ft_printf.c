/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:23:58 by jko               #+#    #+#             */
/*   Updated: 2020/03/13 18:56:45 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

# include <stdbool.h>


# define ERROR -1
# define SPECIFIER_SET "cspdiuxXnfge%"

typedef struct	s_data
{
	va_list		ap;
	const char	*format;
	int		written_len;
}		t_data;
 

typedef struct	s_format_tag
{
	bool	sign;
	bool	sign_space;
	bool	sharp;
	bool	fill_zero;
	char	length;
	char	specifier;
	int	width;
	int	precision;
}		t_format_tag;


static t_format_tag parse_tag(const char *str)
{
}

static t_format_tag	*ft_printf_get_tag(const char *tag, t_data *data)
{
	size_t	len;
	char	*spec_c;

	if (tag == 0)
		return (0);
	if (!(spec_c = ft_strchrset(tag + 1, SPECIFIER_SET)))
		return (0);
	len = spec_c - tag;
	data->format += len + 1;
	return (ft_strndup(tag, len));
}


static int	ft_printf_str(t_format_tag *tag, t_data *data)
{
	int len;

	len = -1;
	if (tag->specifier == 'c' || tag->specifier == 's')
		len = ft_putchar_fd(va_arg(data->ap, int), 1);
	else if (tag->specifier == 's')
		len = ft_putstr_fd(va_arg(data->ap, char *), 1);
	if (len <= 0)
		return (ERROR);
	data->written_len += len;
	return (data->written_len);
}

static int	ft_printf_format(t_format_tag *tag, t_data *data)
{
	size_t	len;

	if (tag == 0 || data == 0)
		return (ERROR);
	if (tag->specifier == 'c' || tag->specifier == 's')
		return (ft_printf_str(tag, data));
	return (ERROR);
}

static bool	ft_printf_print_text(t_data *data, size_t write_len)
{
	int len;

	len = write(1, data->format, write_len);
	if (len < 0)
		return (false);
	data->written_len += len;
	data->format += len;
	return (true);
}

static int	ft_printf_print(t_data *data)
{
	char		*specifier;
	t_format_tag	*tag;
	int		result;

	while ((specifier = ft_strchr(data->format, '%')) != 0)
	{
		if (!ft_printf_print_text(data, specifier - data->format)
				|| !(tag = ft_printf_get_tag(specifier, data)))
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
