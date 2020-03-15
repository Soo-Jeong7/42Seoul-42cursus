/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tag_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 18:31:54 by jko               #+#    #+#             */
/*   Updated: 2020/03/15 23:47:39 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_format_tag	*init_tag(void)
{
	t_format_tag *tag;

	if (!(tag = malloc(sizeof(t_format_tag))))
		return (NULL_POINTER);
	tag->left_align = false;
	tag->sign = false;
	tag->sign_space = false;
	tag->sharp = false;
	tag->fill_zero = false;
	tag->length = false;
	tag->specifier = NULL_CHAR;
	tag->width = 0;
	tag->precision = 0;
	return (tag);
}

static char	*parse_specicier(char *tag_str, t_format_tag *tag)
{
	char	*specifier_addr;
	char	c;

	if (!tag_str || !tag
			|| !(specifier_addr = ft_strchr(TAG_SPECIFIER_SET, *tag_str)))
		return (NULL_POINTER);
	c = TAG_SPECIFIER_SET[specifier_addr - TAG_SPECIFIER_SET];
	tag->specifier = c;
	tag_str++;
	return (tag_str);
}

static t_format_tag	*parse_tag(char *tag_str, t_data *data)
{
	t_format_tag	*tag;

	if (!tag_str || !data || !(tag = init_tag()))
		return (NULL_POINTER);
	if (!(tag_str = ft_printf_parse_tag_option(tag_str, tag, data))
			|| !(tag_str = parse_specicier(tag_str, tag)))
	{
		free(tag);
		tag = NULL_POINTER;
	}
	return (tag);
}

t_format_tag	*ft_printf_get_tag(const char *start, t_data *data)
{
	char		*end;
	char		*tag_str;
	t_format_tag	*tag;
	size_t		len;

	start += 1;
	if (start == 0 || data == 0
			|| !(end = ft_strchrset(start, TAG_SPECIFIER_SET)))
		return (NULL_POINTER);
	len = end - start + 1;
	data->format += len + 1;
	if (!(tag_str = ft_strndup(start, len)))
		return (NULL_POINTER);
	tag = parse_tag(tag_str, data);
	free(tag_str);
	return (tag);
}
