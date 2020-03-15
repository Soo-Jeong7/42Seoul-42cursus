/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tag_option_parser.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 18:11:39 by jko               #+#    #+#             */
/*   Updated: 2020/03/15 18:47:47 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*parse_flags(char *tag_str, t_format_tag *tag)
{
	char	*flag_addr;
	char	flag;

	while ((flag_addr = ft_strchr(TAG_FLAG_SET, *tag_str)))
	{
		flag = TAG_FLAG_SET[flag_addr - TAG_FLAG_SET];
		if (flag == '-')
			tag->left_align = true;
		else if (flag == '+')
			tag->sign = true;
		else if (flag == ' ')
			tag->sign_space = true;
		else if (flag == '#')
			tag->sharp = true;
		else if (flag == '0')
			tag->fill_zero = true;
		else
			return (NULL_POINTER);
		tag_str++;
	}
	return (tag_str);
}

static char	*parse_width(char *tag_str, t_format_tag *tag, t_data *data)
{
	char	*c_addr;
	int	n;

	if (*tag_str == '*')
	{
		n = va_arg(data->ap, int);
		if (n < 0)
		{
			tag->left_align = true;
			n *= -1;
		}
		tag->width = n;
		return (++tag_str);
	}
	if (!ft_isdigit(*tag_str) || *tag_str == '0')
		return (tag_str);
	while ((c_addr = ft_strchr(DIGIT_STR, *tag_str)))
	{
		n = DIGIT_STR[c_addr - DIGIT_STR] - '0';
		tag->width = tag->width * 10 + n;
		tag_str++;
	}
	return (tag_str);
}

static char	*parse_precision(char *tag_str, t_format_tag *tag, t_data *data)
{
	char	*c_addr;
	int	n;

	if (*tag_str != '.')
		return (tag_str);
	tag_str++;
	if (*tag_str == '*')
	{
		n = va_arg(data->ap, int);
		if (n < 0)
			n = 0;
		tag->precision = n;
		return (++tag_str);
	}
	while ((c_addr = ft_strchr(DIGIT_STR, *tag_str)))
	{
		n = DIGIT_STR[c_addr - DIGIT_STR] - '0';
		tag->precision = tag->precision * 10 + n;
		tag_str++;
	}
	return (tag_str);
}

static char	*parse_length(char *tag_str, t_format_tag *tag)
{
	if (*tag_str == 'l')
	{
		tag->length = TAG_LENGTH_L;
		tag_str++;
		if (*tag_str == 'l')
		{
			tag->length = TAG_LENGTH_LL;
			tag_str++;
		}
	}
	else if (*tag_str == 'h')
	{
		tag->length = TAG_LENGTH_H;
		tag_str++;
		if (*tag_str == 'h')
		{
			tag->length = TAG_LENGTH_HH;
			tag_str++;
		}
	}
	return (tag_str);
}

char		*ft_printf_parse_tag_option(char *str, t_format_tag *tag, t_data *data)
{
	if (str == NULL_POINTER
			|| tag == NULL_POINTER
			|| data == NULL_POINTER
			|| !(str = parse_flags(str, tag))
			|| !(str = parse_width(str, tag, data))
			|| !(str = parse_precision(str, tag, data))
			|| !(str = parse_length(str, tag)))
		return (NULL_POINTER);
	return (str);
}
