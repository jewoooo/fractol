/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:13:45 by jewlee            #+#    #+#             */
/*   Updated: 2023/10/26 13:47:33 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*test1;
	t_list	*test2;
	t_list	*test3;
	t_list	*test4;
	t_list	*check;
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
	check = ft_lstlast(test1);
	printf("%s\n", check->content);
}
*/