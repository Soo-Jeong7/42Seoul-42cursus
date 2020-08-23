/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:34:23 by jko               #+#    #+#             */
/*   Updated: 2020/04/07 18:17:16 by jko              ###   ########.fr       */
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

int			ft_printf_wchar(wint_t c, t_format_tag *tag, t_data *data)
{
	char	*str;
	wchar_t	wstr[2];
	int		result;

	if (!tag || !data)
		return (ERROR);
	wstr[0] = c;
	wstr[1] = L'\0';
	str = ft_wchars_to_str(wstr);
	if (!str)
		return (ERROR);
	result = print_str(&str, tag, data);
	free(str);
	return (result);
}

int			ft_printf_str(t_format_tag *tag, t_data *data)
{
	char	*str;
	wchar_t	*wstr;
	int		result;

	if (!tag || !data)
		return (ERROR);
	if (tag->length == TAG_LENGTH_L)
	{
		wstr = va_arg(data->ap, wchar_t *);
		str = ft_wchars_to_str(wstr);
	}
	else
	{
		if ((str = va_arg(data->ap, char *)))
			str = ft_strdup(str);
	}
	result = print_str(&str, tag, data);
	free(str);
	return (result);
}
