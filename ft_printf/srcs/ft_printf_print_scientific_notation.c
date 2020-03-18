/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_scientific_notation.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:28:46 by jko               #+#    #+#             */
/*   Updated: 2020/03/18 23:19:04 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


typedef struct	s_double_value
{
	double	n;
	double	mantissa;
	long long	head;
	long long	tail;
	int	exponent;
	bool	is_negative;
	bool	exponent_is_negative;
}		t_double_value;

typedef struct	s_scientific_notation
{
	char	*head;
	char	*tail;
	char	*exponent;
	bool	is_negative;
	bool	exponent_is_negative;
}		t_scientific_notation;

static bool	get_exponent_and_mantissa(double n, t_double_value *d)
{
	int	exponent;

	exponent = 0;
	if (n < 1)
	{
		while (n < 1)
		{
			n *= 10;
			exponent--;
		}
	}
	else
	{
		while (n > 10)
		{
			n *= 0.1;
			exponent++;
		}
	}
	d->exponent_is_negative = exponent < 0;
	d->exponent = exponent < 0 ? exponent * -1 : exponent;
	d->mantissa = n;
	return (true);
}

static bool	get_head_tail(t_double_value *d)
{
	long long	tail;
	long long	temp;
	double		t;

	d->head = (int)d->mantissa;
	tail = 0;
	temp = 0;
	t = (d->mantissa - d->head) * 10;
	while (t > temp)
	{
		temp = (long long)t;
		tail = tail * 10 + temp;
		t = (t - temp) * 10;
	}
	d->tail = tail;
	return (true);
}


static t_scientific_notation	*get_e_str(t_double_value *d)
{
	t_scientific_notation	*sn;
	char			*temp;

	if (!d || !(sn = malloc(sizeof(t_scientific_notation))))
		return (0);
	sn->is_negative = d->is_negative;
	sn->exponent = ft_itoa(d->exponent);
	if (d->exponent < 10)
	{
		if (!(temp = malloc(ft_strlen(sn->exponent + 2))))
		{
			free(sn);
			return (0);
		}
		temp[0] = '0';
		ft_strlcpy(temp + 1, sn->exponent, 2);
		free(sn->exponent);
		sn->exponent = temp;
	}
	sn->head = ft_itoa(d->head);
	sn->tail = ft_itoa(d->tail);
	if (!sn->head || !sn->tail || !sn->exponent)
	{
		free(sn->head);
		free(sn->tail);
		free(sn->exponent);
		free(sn);
		return (0);
	}
	return (sn);
}

static t_double_value *get_double_value(double n)
{
	t_double_value *d;

	if (!(d = malloc(sizeof(t_double_value))))
		return (0);
	if (n < 0)
	{
		d->is_negative = true;
		n *= -1;
	}
	d->n = n;
	if (!get_exponent_and_mantissa(n, d)
			|| !(get_head_tail(d)))
	{
		free(d);
		return (0);
	}
	return (d);
}

static char	*get_str(t_scientific_notation *sn, size_t *len, t_format_tag *tag, bool is_upper)
{
	char	*result;

	if (!sn || !tag)
		return (false);
	*len = ft_strlen(sn->head) + ft_strlen(sn->tail) + ft_strlen(sn->exponent) + 4;
	if (!(result = malloc(*len)))
		return (false);
	ft_strlcpy(result, sn->head, *len);
	ft_strlcat(result, ".", *len);
	ft_strlcat(result, sn->tail, *len);
	ft_strlcat(result, is_upper ? "E" : "e", *len);
	ft_strlcat(result, sn->exponent_is_negative ? "-" : "+", *len);
	ft_strlcat(result, sn->exponent, *len);
	*len -= 1;
	return (result);
}

static bool	add_sign(char **str, size_t *len,
		t_scientific_notation *sn, t_format_tag *tag)
{
	char	*temp;

	if (!str || !*str || !tag)
		return (false);
	if (!sn->is_negative && !tag->sign && !tag->sign_space)
		return (true);
	if (!(temp = malloc(*len + 2)))
		return (false);
	*len += 1;
	temp[0] = tag->sign ? '+' : ' ';
	temp[0] = sn->is_negative ? '-' : temp[0];
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


static bool	apply_precision_double(t_scientific_notation *sn, t_format_tag *tag)
{
	char	*temp;
	size_t	len;
	size_t	new_len;

	if (!sn || !tag)
		return (false);
	len = ft_strlen(sn->tail);
	if ((tag->precision < 0 && len >= 6) || len >= (size_t)tag->precision)
		return (true);
	new_len = tag->precision < 0 ? 7 : (tag->precision + 1);
	if (!(temp = malloc(new_len)))
		return (false);
	ft_strlcpy(temp, sn->tail, new_len);
	ft_memset(temp + len, '0', new_len - len - 1);
	temp[new_len] = NULL_CHAR;
	free(sn->tail);
	sn->tail = temp;
	return (true);
}

#include <stdio.h>
static int	print_e_num(t_scientific_notation *sn, t_format_tag *tag, t_data *data)
{
	char	*str;
	size_t	len;
	int	result;

	if (!sn || !tag || !data)
		return (ERROR);
	str = 0;
	if (!apply_precision_double(sn, tag)
			|| !(str = get_str(sn, &len, tag, tag->specifier == 'E'))
			|| !(add_sign(&str, &len, sn, tag))
			|| !apply_alignment(&str, &len, tag)
			|| !move_sign(str, tag, sn->is_negative))
	{
		free(str);
		return (ERROR);
	}
	data->written_len += len;
	result = ft_putstr_fd(str, 1);
	free(str);
	return (result);
}

int		ft_printf_scientific_notation(
		t_format_tag *tag, t_data *data)
{
	t_double_value		*d;
	t_scientific_notation	*sn;
	double	arg;
	int	result;

	if (!tag || !data)
		return (ERROR);
	arg = va_arg(data->ap, double);
	
	if (!(d = get_double_value(arg)))
		return (ERROR);
	if (!(sn = get_e_str(d)))
	{
		free(d);
		return (ERROR);
	}
	result = print_e_num(sn, tag, data);
	free(sn);
	return (result);
}
