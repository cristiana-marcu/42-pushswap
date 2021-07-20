/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:26:27 by cmarcu            #+#    #+#             */
/*   Updated: 2021/07/20 17:00:22 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap_checker.h"

void	push_swap_fill(int argc, char **argv, t_swap *swap)
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

void	do_swappush_no_print(t_swap *swap, char *line)
{
	if (!(ft_strncmp("sa", line, 2)))
		do_rule_no_printing(swap, "sa");
	else if (!(ft_strncmp("sb", line, 2)))
		do_rule_no_printing(swap, "sb");
	else if (!(ft_strncmp("ss", line, 2)))
		do_rule_no_printing(swap, "ss");
	else if (!(ft_strncmp("pb", line, 2)))
		do_rule_no_printing(swap, "pb");
	else if (!(ft_strncmp("pa", line, 2)))
		do_rule_no_printing(swap, "pa");
	else
		print_error();
}

void	push_swap_checker(t_swap *swap)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!(ft_strncmp("ra", line, 2)))
			do_rule_no_printing(swap, "ra");
		else if (!(ft_strncmp("rb", line, 2)))
			do_rule_no_printing(swap, "rb");
		else if (!(ft_strncmp("rra", line, 3)))
			do_rule_no_printing(swap, "rra");
		else if (!(ft_strncmp("rrb", line, 3)))
			do_rule_no_printing(swap, "rrb");
		else if (!(ft_strncmp("rrr", line, 3)))
			do_rule_no_printing(swap, "rrr");
		else if (!(ft_strncmp("rr", line, 2)))
			do_rule_no_printing(swap, "rr");
		else
			do_swappush_no_print(swap, line);
		free(line);
	}
	free(line);
	if (check_sorted(swap->stack_a) && !swap->stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_swap	push_swap;

	if (argc < 2)
		return (0);
	push_swap_fill(argc, argv, &push_swap);
	push_swap_checker(&push_swap);
}
