/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:23:58 by jko               #+#    #+#             */
/*   Updated: 2020/03/22 17:45:52 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool		apply_alignment(char **str, size_t *len, t_format_tag *tag)
{
	char	*temp;

	if (!str || !*str || !tag | !len)
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
		ft_memset(temp, tag->fill_zero && (tag->precision < 0 ||
				ft_strchr("eE", tag->specifier)) ? '0' : ' ',
				tag->width - *len);
		ft_strlcpy(temp + tag->width - *len, *str, *len + 1);
	}
	free(*str);
	*str = temp;
	*len = tag->width;
	return (true);
}

static bool	apply_precision2(char **str, size_t *len, t_format_tag *tag)
{
	char	*temp;

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
	return (apply_precision2(str, len, tag));
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
