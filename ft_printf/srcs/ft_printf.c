/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:23:58 by jko               #+#    #+#             */
/*   Updated: 2020/03/13 01:21:50 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

# define SPECIFIER_SET "cspdiuxXnfge%"

typedef struct	s_data
{
	va_list		ap;
	const char	*format;
	int		written_len;
}		t_data;
 

static char	*ft_printf_get_specifier(const char *specifier)
{
	size_t	len;
	char	*spec_c;

	if (specifier == 0)
		return (0);
	if (!(spec_c = ft_strchrset(specifier, SPECIFIER_SET)))
		return (0);
	len = spec_c - specifier + 1;
	return (ft_strndup(specifier, len));
}

static int	ft_printf_format(const char *specifier, t_data *data)
{
	size_t	len;

	if (specifier == 0 || data == 0)
		return (-1);
	len = ft_strlen(specifier);
	if (specifier[len - 1] == 'c')
		return (ft_putchar_fd(va_arg(data->ap, int), 1));
	if (specifier[len - 1] == 's')
		return (ft_putstr_fd(va_arg(data->ap, char *), 1));
	return (-1);
}

static int	ft_printf_print(t_data *data)
{
	char	*specifier;
	size_t	i;
	int	len;

	i = 0;
	while ((specifier = ft_strchr(data->format + i, '%')) != 0)
	{
		if ((len = write(1, data->format + i, specifier - data->format - i)) < 0)
			return (-1);
		data->written_len += len;
		if (!(specifier = ft_printf_get_specifier(specifier + 1)))
			return (-1);
		i += len + ft_strlen(specifier) + 1;
		len = ft_printf_format(specifier, data);
		free(specifier);
		if (len < 0)
			return (-1);
		data->written_len += len;
	}
	if ((len = write(1, data->format + i, ft_strlen(data->format + i))) < 0)
		return (-1);
	data->written_len += len;
	return (data->written_len);
}

int		ft_printf(const char *format, ...)
{
	t_data	data;
	
	if (format == 0)
		return (-1);
	va_start(data.ap, format);
	data.format = format;
	data.written_len = 0;
	if (ft_printf_print(&data) < 0)
		data.written_len = -1;
	va_end(data.ap);
	return (data.written_len);
}
