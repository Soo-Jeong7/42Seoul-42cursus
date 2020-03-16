/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 13:43:43 by jko               #+#    #+#             */
/*   Updated: 2020/03/16 14:55:53 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_alignment_char(t_format_tag *tag, size_t *len)
{
	char	*temp;
	char	c;

	if (tag == NULL_POINTER)
		return (NULL_POINTER);
	if (1 >= (size_t)tag->width)
		return (ft_strdup(""));
	if (!(temp = malloc(tag->width)))
		return (false);
	c = ' ';
	if (!(tag->left_align) && tag->fill_zero)
		c = '0';
	ft_memset(temp, c, tag->width - 1);
	temp[tag->width - 1] = NULL_CHAR;
	*len = tag->width;
	return (temp);
}

static int	print_char(char c, t_format_tag *tag, t_data *data)
{
	size_t	len;
	char	*str;
	int	result1;
	int	result2;

	if (!tag || !data)
		return (ERROR);
	len = 1;
	if (!(str = apply_alignment_char(tag, &len)))
		return (ERROR);
	data->written_len += len;
	if (tag->left_align)
	{
		result1 = ft_putchar_fd(c, 1);
		result2 = ft_putstr_fd(str, 1);
	}
	else
	{
		result2 = ft_putstr_fd(str, 1);
		result1 = ft_putchar_fd(c, 1);
	}
	free(str);
	if (result1 != 1 || result2 < 0)
		return (ERROR);
	return (len);
}

int		ft_printf_percent(t_format_tag *tag, t_data *data)
{
	int	result;

	if (!tag || !data)
		return (ERROR);
	result = print_char('%', tag, data);
	return (result);
}

int		ft_printf_char(t_format_tag *tag, t_data *data)
{
	char	c;
	int	result;

	if (!tag || !data)
		return (ERROR);
	c = va_arg(data->ap, int);
	result = print_char(c, tag, data);
	return (result);
}
