/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:32:35 by jewlee            #+#    #+#             */
/*   Updated: 2023/10/26 14:22:38 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == 0 || del == 0)
		return ;
	del(lst->content);
	free(lst);
	lst = 0;
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
	t_list	*test;
	char	*ptr = "hello world!";
	void	(*f)(void *a);

	f = del_content;
	test = ft_lstnew(ptr);
	printf("%s\n", test->content);
	ft_lstdelone(test, f);
	printf("%s\n", test->content);
}
*/