/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:25:18 by jewlee            #+#    #+#             */
/*   Updated: 2023/10/26 13:48:19 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != 0)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
/*
#include <stdio.h>

int	main(void)
{
	int		lst_size;
	t_list	*test1;
	t_list	*test2;
	t_list	*test3;
	t_list	*test4;
	char	*ptr1 = "1";
	char	*ptr2 = "2";
	char	*ptr3 = "3";
	char	*ptr4 = "4";

	test1 = ft_lstnew((void *)ptr1);
	test2 = ft_lstnew((void *)ptr2);
	test3 = ft_lstnew((void *)ptr3);
	test4 = ft_lstnew((void *)ptr4);
	test1->next = test2;
	test2->next = test3;
	test3->next = test4;
	lst_size = ft_lstsize(test1);
	printf("%d\n", lst_size);
}
*/