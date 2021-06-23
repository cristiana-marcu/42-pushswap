/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:09:38 by cmarcu            #+#    #+#             */
/*   Updated: 2021/06/01 17:27:05 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# include <stdio.h> // Printf, scanf

static int	ft_isspace(char *str)
{
	int	a;

	a = 0;
	while (str[a] == '\t' || str[a] == '\n' || str[a] == '\v'
		|| str[a] == '\f' || str[a] == '\r' || str[a] == ' ')
		a++;
	return (a);
}

int	ft_atoi(const char *str)
{
	int	a;
	int	number;
	int	is_neg;

	a = ft_isspace((char *)str);
	is_neg = 0;
	number = 0;
	if (str[a] == '-')
	{
		a++;
		is_neg = 1;
	}
	else if (str[a] == '+')
		a++;
	if (str[a] == '\0' || str[a] < '0' || str[a] > '9')
		printf("Invalid number");
	while (str[a] >= '0' && str[a] <= '9')
	{
		number = number * 10 + (str[a] - '0');
		a++;
	}
	if (is_neg)
		return (-number);
	else
		return (number);
}
