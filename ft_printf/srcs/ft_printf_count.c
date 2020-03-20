/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:34:23 by jko               #+#    #+#             */
/*   Updated: 2020/03/20 16:43:31 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_count(t_format_tag *tag, t_data *data)
{
	int *len;

	if (!tag || !data)
		return (ERROR);
	if (!(len = va_arg(data->ap, int *)))
		return (ERROR);
	*len = data->written_len;
	return (0);
}
