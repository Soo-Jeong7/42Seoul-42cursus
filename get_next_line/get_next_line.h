/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:45:02 by jko               #+#    #+#             */
/*   Updated: 2020/03/07 14:58:41 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int	get_next_line(int fd, char **line);

void	*ft_memchr(void *addr, int c, size_t size);
void	*ft_memcpy(void *dst, void *src, size_t n);

#endif
