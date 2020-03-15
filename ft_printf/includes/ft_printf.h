/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:24:27 by jko               #+#    #+#             */
/*   Updated: 2020/03/15 23:19:10 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ERROR -1
# define NULL_POINTER 0
# define NULL_CHAR 0

# define DIGIT_STR "0123456789"
# define HEX_DIGIT_STR "0123456789abcdef"

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

typedef struct	s_data
{
	va_list		ap;
	const char	*format;
	int		written_len;
}		t_data;
 
typedef struct	s_format_tag
{
	bool	left_align;
	bool	sign;
	bool	sign_space;
	bool	sharp;
	bool	fill_zero;
	char	length;
	char	specifier;
	int	width;
	int	precision;
}		t_format_tag;

int		ft_printf(const char *, ...);

char		*ft_printf_parse_tag_option(char *str, t_format_tag *tag, t_data *data);
t_format_tag	*ft_printf_get_tag(const char *start, t_data *data);


#endif
