/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:02:00 by cmarcu            #+#    #+#             */
/*   Updated: 2021/05/26 14:45:30 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void fill_stack(t_swap *swap, int argc, char **argv)
{
	int i;

	i = 1;
	swap->numbers = (int **)malloc(sizeof(int *) * argc - 1);
	while (argv[i])
	{
		swap->numbers[0][i - 1] = ft_atoi(argv[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	int 	i;
	int 	j;
	t_swap	*swap;

	i = 1;
	if (argc < 2)
		return (0);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] <= '9' && argv[i][j] >= '0')
			|| (j == 0 && argv[i][j] == '-')))
				return (printf("Error\n"));
			j++;
		}
		i++;
	}
	printf("im in");
	swap = malloc(sizeof(t_swap));
	fill_stack(swap, argc, argv);
	printf("Number of args: %d\n", argc);
	printf("Number of nums: %d", i);
}
