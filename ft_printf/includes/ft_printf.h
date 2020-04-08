/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:24:27 by jko               #+#    #+#             */
/*   Updated: 2020/04/07 18:26:58 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define TAG_FLAG_SET "-+ #0"
# define TAG_LENGTH_HH 1
# define TAG_LENGTH_H 2
# define TAG_LENGTH_L 3
# define TAG_LENGTH_LL 4
# define TAG_SPECIFIER_SET "cspdiuxXnfge%"

# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <wchar.h>

typedef struct	s_data
{
	va_list		ap;
	const char	*format;
	int			written_len;
}				t_data;

typedef struct	s_format_tag
{
	bool	left_align;
	bool	sign;
	bool	sign_space;
	bool	sharp;
	bool	fill_zero;
	char	length;
	char	specifier;
	int		width;
	int		precision;
}				t_format_tag;

typedef struct	s_double_value
{
	double		n;
	double		mantissa;
	long long	head;
	char		*tail;
	int			exponent;
	bool		is_negative;
	bool		exponent_is_negative;
}				t_double_value;

typedef struct	s_scientific_notation
{
	char	*head;
	char	*tail;
	char	*exponent;
	bool	is_negative;
	bool	exponent_is_negative;
}				t_scientific_notation;

int				ft_printf(const char *format, ...);

char			*ft_printf_parse_tag_option(
				char *str, t_format_tag *tag, t_data *data);
t_format_tag	*ft_printf_get_tag(const char *start, t_data *data);

bool			apply_alignment(char **str, size_t *len, t_format_tag *tag);
bool			apply_precision(char **str, size_t *len, t_format_tag *tag);
bool			apply_flag_sharp(
				char **s, size_t *len, t_format_tag *t, bool is_zero);

int				ft_printf_str(t_format_tag *tag, t_data *data);
int				ft_printf_percent(t_format_tag *tag, t_data *data);
int				ft_printf_char(t_format_tag *tag, t_data *data);
int				ft_printf_pointer(t_format_tag *tag, t_data *data);
int				ft_printf_unsigned_number(
				t_format_tag *tag, t_data *data, char *base);
int				ft_printf_signed_number(t_format_tag *tag, t_data *data);
int				ft_printf_scientific_notation(t_format_tag *tag, t_data *data);
int				ft_printf_count(t_format_tag *tag, t_data *data);
int				ft_printf_wchar(wint_t c, t_format_tag *tag, t_data *data);

#endif
