/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:42:00 by jewlee            #+#    #+#             */
/*   Updated: 2023/10/13 16:34:40 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n > 0)
	{
		if (*((unsigned char *)s1) != *((unsigned char *)s2))
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		n--;
		s1++;
		s2++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	int	a[] = {214, 2};
	int	b[] = {214, 2};

	printf("\nreturn = %d\n", ft_memcmp(a, b, sizeof(a)));
}
*/