/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:45:02 by jko               #+#    #+#             */
/*   Updated: 2020/04/07 18:01:36 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
# endif

typedef struct	s_info
{
	char	buf[BUFFER_SIZE + 1];
	char	*remainder[OPEN_MAX];
}				t_info;

int				get_next_line(int fd, char **line);

size_t			ft_strlen(const char *s);
char			*ft_strchr(char *str, int c);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
