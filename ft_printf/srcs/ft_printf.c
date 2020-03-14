/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:23:58 by jko               #+#    #+#             */
/*   Updated: 2020/03/14 21:48:54 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

# include <stdbool.h>


# define ERROR -1
# define NULL_POINTER 0
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

static char		*parse_flags(char *tag_str, t_format_tag *tag)
{
}

static char		*parse_width(char *tag_str, t_format_tag *tag)
{
}

static char		*parse_precision(char *tag_str, t_format_tag *tag)
{
}

static char		*parse_length(char *tag_str, t_format_tag *tag)
{
}

static char		*parse_specicier(char *tag_str, t_format_tag *tag)
{
}

static t_format_tag	*parse_tag(char *tag_str)
{
	t_format_tag	*tag;

	if (tag_str == 0 || !(tag = malloc(sizeof(t_format_tag))))
		return (NULL_POINTER);
	if (!(tag_str = parse_flags(tag_str, tag))
			|| !(tag_str = parse_width(tag_str, tag))
			|| !(tag_str = parse_precision(tag_str, tag))
			|| !(tag_str = parse_length(tag_str, tag))
			|| !(tag_str = parse_specicier(tag_str, tag)))
	{
		free(tag);
		tag = 0;
	}
	return (tag);
}

static t_format_tag	*ft_printf_get_tag(const char *start, t_data *data)
{
	char		*end;
	char		*tag_str;
	t_format_tag	*tag;
	size_t		len;

	start += 1;
	if (start == 0 || data == 0
			|| !(end = ft_strchrset(start, SPECIFIER_SET)))
		return (NULL_POINTER);
	len = end - start - 1;
	data->format += len + 1;
	if (!(tag_str = ft_strndup(start, len)))
		return (NULL_POINTER);
	tag = parse_tag(tag_str);
	free(tag_str);
	return (tag);
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
