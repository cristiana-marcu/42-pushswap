/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:26:27 by cmarcu            #+#    #+#             */
/*   Updated: 2021/07/05 18:27:52 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap_checker.h"

void	free_split(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	if (temp)
		free(temp);
}

void push_swap_fill(int argc, char **argv, t_swap *swap)
{
	int		i;
	int		j;
	int		num;
	char	**temp;

	j = 1;
	while (j < argc)
	{
		temp = ft_split(argv[j], ' ');
		i = 0;
		while (temp[i])
		{
			check_for_letters(i, temp);
			num = ft_atoi(temp[i]);
			swap->repeated = num;
			check_repeated(swap, swap->stack_a);
			ft_lstadd_back(&swap->stack_a, ft_lstnew(num));
			i++;
		}
		free_split(temp);
		j++;
	}
	swap->lst_length = ft_lstsize(swap->stack_a);
}

void	push_swap_checker(t_swap *swap)
{
	//int		n;
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!(ft_strncmp("sa", line, 2)))
			sa(swap);
		else if (!(ft_strncmp("sb", line, 2)))
			sb(swap);
		//else if (ft_strncmp("ra", line, 2))
			//rx(swap, swap, "ra");
	}
}

int main(int argc, char **argv)
{
	t_swap push_swap;

	if (argc < 2)
	 	return (0);
	push_swap_fill(argc, argv, &push_swap);
	check_sorted(push_swap.stack_a);
	push_swap_checker(&push_swap);
	//printf("Number of moves: %d\n", push_swap.moves);
	//ft_lstiter(push_swap.stack_a, f);
	//printf("Number of moves: %d\n", push_swap.moves);
	//ft_lstiter(push_swap.stack_a, f);
	//system("leaks push_swap");
}
