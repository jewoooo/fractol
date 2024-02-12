/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:38:41 by jewlee            #+#    #+#             */
/*   Updated: 2023/10/26 14:24:10 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst == 0 || del == 0)
		return ;
	while (*lst != 0)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = 0;
}
/*
#include <stdio.h>

void	del_content(void *content)
{
	free(content);
	content = 0;
}

int	main(void)
{
	t_list	*test1;
	t_list	*test2;
	t_list	*test3;
	char	*ptr1 = "1";
	char	*ptr2 = "2";
	char	*ptr3 = "3";
	void	(*f)(void *a);

	f = del_content;
	test1 = ft_lstnew((void *)ptr1);
	test2 = ft_lstnew((void *)ptr2);
	test3 = ft_lstnew((void *)ptr3);
	test1->next = test2;
	test2->next = test3;
	printf("%s\n", test1->content);
	printf("%s\n", test2->content);
	printf("%s\n", test3->content);
	ft_lstclear(&test1, f);
	printf("%s\n", test1->content);
	printf("%s\n", test2->content);
	printf("%s\n", test3->content);
}
*/