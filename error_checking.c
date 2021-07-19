/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAMON <RAMON@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:55:52 by cmarcu            #+#    #+#             */
/*   Updated: 2021/07/19 16:08:59 by RAMON            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	f(int n)
{
	printf("%d\n", n);
}

void	print_error(void)
{
	printf("Error\n");
	exit(1);
}

void	check_repeated(t_swap *swap, t_list *stack_a)
{
	t_list	*ptr;

	if (stack_a)
	{
		while (stack_a)
		{
			if (stack_a->content == swap->repeated)
				print_error();
			ptr = stack_a->next;
			stack_a = ptr;
		}
	}
}

void	check_for_letters(int i, char **argv)
{
	int	j;

	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] <= '9' && argv[i][j] >= '0')
			|| (j == 0 && argv[i][j] == '-') || (j == 0 && argv[i][j] == '+')))
				print_error();
			j++;
		}
		i++;
	}
}

int	check_sorted(t_list *lst)
{
	int		n;
	t_list	*next;

	if (lst)
	{
		while (lst)
		{
			n = lst->content;
			next = lst->next;
			if (next)
				if (n > next->content)
					return (0);
			lst = next;
		}
		if (lst == NULL)
			return (1);
	}
	return (0);
}
