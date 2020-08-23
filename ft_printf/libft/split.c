/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:26:14 by jko               #+#    #+#             */
/*   Updated: 2020/08/23 23:47:21 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**make_blank(char *s)
{
	char	**result;

	if ((result = (char **)malloc(sizeof(char *) * 2)) == 0)
	{
		free(s);
		return (0);
	}
	result[0] = s;
	result[1] = 0;
	return (result);
}

static int	get_word_count(char *s, char c)
{
	int	i;
	int	prev;
	int	count;

	count = 0;
	i = 0;
	prev = -1;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (i > prev + 1)
				count++;
			prev = i;
			s[i] = 0;
		}
		i++;
	}
	if (s[i - 1] != 0)
		count++;
	return (count);
}

static char	**free_arr(char **arr)
{
	size_t i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

static char	**fill_words(char *s, int count)
{
	size_t	i;
	char	**result;
	int		j;

	if ((result = (char **)malloc(sizeof(char *) * (count + 1))) == 0)
		return (0);
	i = 0;
	j = 0;
	while (j < count)
	{
		if (s[i])
		{
			if ((result[j] = ft_strdup(s + i)) == 0)
				return (free_arr(result));
			i += ft_strlen(result[j]);
			j++;
		}
		i++;
	}
	result[j] = 0;
	return (result);
}

char		**ft_split(char const *s, char c)
{
	char	**result;
	char	*s2;
	int		count;

	if (s == 0 || (s2 = ft_strdup(s)) == 0)
		return (0);
	if (ft_strlen(s) == 0)
		return (make_blank(s2));
	count = get_word_count(s2, c);
	result = fill_words(s2, count);
	free(s2);
	return (result);
}
