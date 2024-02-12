/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:02:28 by jewlee            #+#    #+#             */
/*   Updated: 2023/10/26 13:47:56 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == 0 || new == 0)
		return ;
	new->next = *lst;
	*lst = new;
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
	t_list	*test_n;
	char	*ptr1 = "hello world";
	char	*ptr2 = "my name is ";
	char	*ptr3 = "my name is ";
	char	*ptr = "this is for test";
	char	*ptr_n = "test for null";

	test1 = ft_lstnew((void *)ptr1);
	test1->next = test2;
	test2 = ft_lstnew((void *)ptr2);
	test2->next = test3;
	test3 = ft_lstnew((void *)ptr3);
	null_test = 0;
	test_n = ft_lstnew((void *)ptr_n);
	test = ft_lstnew((void *)ptr);
	ft_lstadd_front(&test1, test);
	ft_lstadd_front(&null_test, test_n);
	printf("%s\n", (test->next)->content);
	printf("%s\n", null_test->content);
}
*/