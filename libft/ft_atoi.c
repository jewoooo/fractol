/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:05:23 by jewlee            #+#    #+#             */
/*   Updated: 2023/10/24 16:23:31 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			flag;
	long long	res;

	flag = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' && (*(str + 1) >= '0' && *(str + 1) <= '9'))
	{
		flag = 1;
		str++;
	}
	else if (*str == '+' && (*(str + 1) >= '0' && *(str + 1) <= '9'))
		str++;
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res += (*str - '0');
		str++;
	}
	if (flag == 1)
		res *= (-1);
	return ((int)res);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("%d\n", atoi("-2147483648"));
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", atoi("+000001"));
	printf("%d\n", ft_atoi("+000001"));
	printf("%d\n", atoi("-000001"));
	printf("%d\n", ft_atoi("-000001"));
	printf("%d\n", atoi("+01234"));
	printf("%d\n", ft_atoi("+01234"));
	return (0);
}
*/