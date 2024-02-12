/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:41:21 by jewlee            #+#    #+#             */
/*   Updated: 2023/10/26 14:24:26 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;
	void	*ptr;

	if (lst == 0 || f == 0)
		return (0);
	new_lst = 0;
	while (lst != 0)
	{
		ptr = f(lst->content);
		node = ft_lstnew(ptr);
		if (node == 0)
		{
			del(ptr);
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}

/*
static t_list	*del_ptr(void *content, void (*del)(void *))
{
	del(content);
	content = 0;
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;
	void	*ptr;

	if (lst == 0 || f == 0)
		return (0);
	ptr = f(lst->content);
	new_lst = ft_lstnew(ptr);
	if (new_lst == 0)
		return (del_ptr(ptr, del));
	node = new_lst;
	lst = lst->next;
	while (lst != 0)
	{
		ptr = f(lst->content);
		node->next = ft_lstnew(ptr);
		if (node->next == 0)
		{
			ft_lstclear(&new_lst, del);
			return (del_ptr(ptr, del));
		}
		node = node->next;
		lst = lst->next;
	}
	return (new_lst);
}
*/