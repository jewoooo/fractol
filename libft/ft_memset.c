/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:08:54 by jewlee            #+#    #+#             */
/*   Updated: 2023/10/09 13:02:22 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[] = "Hello World";
	char	str2[] = "Hello World";

	printf("%s\n", memset(str1, 'h', 5));
	printf("%s\n", ft_memset(str2, 'h', 5));
	return (0);
}
*/