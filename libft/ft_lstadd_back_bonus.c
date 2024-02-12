/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:19:18 by jewlee            #+#    #+#             */
/*   Updated: 2023/10/26 13:48:03 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == 0)
		return ;
	if (*lst == 0)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*test1;
	t_list	*test2;
	t_list	*test3;
	t_list	*null_test;
	t_list	*test;
	t_list	*tst;
	char	*ptr1 = "test1";
	char	*ptr2 = "test2";
	char	*ptr3 = "test3";
	char	*ptr = "test last";
	char	*ptr_n = "test for null";

	test1 = ft_lstnew((void *)ptr1);
	test2 = ft_lstnew((void *)ptr2);
	test3 = ft_lstnew((void *)ptr3);
	test1->next = test2;
	test2->next = test3;
	null_test = 0;
	tst = ft_lstnew((void *)ptr_n);
	test = ft_lstnew((void *)ptr);
	ft_lstadd_back(&test1, test);
	ft_lstadd_back(&null_test, tst);
	printf("%s\n", (test3->next)->content);
	printf("%s\n", tst->content);
}
*/