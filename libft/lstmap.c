/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:58:15 by jko               #+#    #+#             */
/*   Updated: 2020/03/01 22:32:37 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*curr;
	t_list	*temp;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	if ((new_head = ft_lstnew(f(lst->content))) == 0)
		return (0);
	curr = new_head;
	lst = lst->next;
	while (lst)
	{
		if ((temp = ft_lstnew(f(lst->content))) == 0)
		{
			ft_lstclear(&new_head, del);
			break ;
		}
		curr->next = temp;
		curr = temp;
		lst = lst->next;
	}
	return (new_head);
}
