/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_signed_num.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:28:46 by jko               #+#    #+#             */
/*   Updated: 2020/04/07 18:19:06 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_minus_sign(char **str, size_t *len)
{
	char	*sign_addr;
	char	*temp;
	char	c;

	if (!str || !*str)
		return (ERROR);
	if (!(sign_addr = ft_strchr(*str, '-')))
		return (false);
	if ((*str)[0] == '0')
	{
		if (!(temp = malloc(*len + 2)))
			return (ERROR);
		*len += 1;
		temp[0] = '0';
		ft_strlcpy(temp + 1, *str, *len);
		free(*str);
		*str = temp;
		if (!(sign_addr = ft_strchr(*str, '-')))
			return (ERROR);
	}
	c = *sign_addr;
	*sign_addr = (*str)[0];
	(*str)[0] = c;
	return (true);
}

static bool	add_sign(char **str, size_t *len, t_format_tag *tag)
{
	char	*temp;
	int		res;

	if (!str || !*str || !tag)
		return (false);
	if ((res = add_minus_sign(str, len)) == true
			|| (!tag->sign && !tag->sign_space))
		return (true);
	if (res == ERROR || !(temp = malloc(*len + 2)))
		return (false);
	*len += 1;
	temp[0] = tag->sign ? '+' : ' ';
	ft_strlcpy(temp + 1, *str, *len);
	free(*str);
	*str = temp;
	return (true);
}

static int	move_sign(char *str, t_format_tag *tag, bool is_negative)
{
	char	*sign_addr;
	char	c;

	if (!str || !*str)
		return (ERROR);
	if (!tag->fill_zero ||
			(!tag->sign && !tag->sign_space && !is_negative))
		return (true);
	if (!(sign_addr = ft_strchrset(str, tag->sign_space ? "+- " : "+-")))
		return (false);
	c = *sign_addr;
	*sign_addr = str[0];
	str[0] = c;
	return (true);
}

static int	print_signed_num(
		char **str, t_format_tag *tag,
		t_data *data)
{
	size_t	len;
	bool	is_negative;

	if (!str || !*str || !tag || !data)
		return (ERROR);
	is_negative = ((*str)[0] == '-') ? true : false;
	len = ft_strlen(*str);
	if (!apply_precision(str, &len, tag)
			|| !add_sign(str, &len, tag)
			|| !apply_alignment(str, &len, tag)
			|| (tag->precision < 0 &&
				!move_sign(*str, tag, is_negative)))
		return (ERROR);
	data->written_len += len;
	return (ft_putstr_fd(*str, 1));
}

int			ft_printf_signed_number(t_format_tag *tag, t_data *data)
{
	char		*str;
	long long	arg;
	int			result;

	if (!tag || !data)
		return (ERROR);
	if (tag->length == TAG_LENGTH_HH)
		arg = (char)va_arg(data->ap, int);
	else if (tag->length == TAG_LENGTH_H)
		arg = (short)va_arg(data->ap, int);
	else if (tag->length == TAG_LENGTH_L)
		arg = (long)va_arg(data->ap, long);
	else if (tag->length == TAG_LENGTH_LL)
		arg = (long long)va_arg(data->ap, long long);
	else
		arg = (int)va_arg(data->ap, int);
	str = ft_lltoa_base((long long)arg, NULL_POINTER);
	if (!str)
		return (ERROR);
	result = print_signed_num(&str, tag, data);
	free(str);
	return (result);
}
