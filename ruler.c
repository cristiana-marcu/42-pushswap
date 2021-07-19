/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruler.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:49:33 by cmarcu            #+#    #+#             */
/*   Updated: 2021/07/06 17:38:22 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	print_rule(char *rule)
{
	if (!(ft_strncmp(rule, "sa", 2)))
		write(1, "sa\n", 3);
	else if (!(ft_strncmp(rule, "sb", 2)))
		write(1, "sb\n", 3);
	else if (!(ft_strncmp(rule, "ss", 2)))
		write(1, "ss\n", 3);
	else if (!(ft_strncmp(rule, "pb", 2)))
		write(1, "pb\n", 3);
	else if (!(ft_strncmp(rule, "pa", 2)))
		write(1, "pa\n", 3);
	else if (!(ft_strncmp(rule, "ra", 2)))
		write(1, "ra\n", 3);
	else if (!(ft_strncmp(rule, "rb", 2)))
		write(1, "rb\n", 3);
	else if (!(ft_strncmp(rule, "rra", 3)))
		write(1, "rra\n", 4);
	else if (!(ft_strncmp(rule, "rrb", 3)))
		write(1, "rrb\n", 4);
	else if (!(ft_strncmp(rule, "rrr", 3)))
		write(1, "rrr\n", 4);
	else if (!(ft_strncmp(rule, "rr", 2)))
		write(1, "rr\n", 3);
	else
		print_error();
}

int	do_swap(t_swap *swap, char *rule)
{
	int	control;

	control = 0;
	if (!(ft_strncmp(rule, "sa", 2)))
		control = sa(swap);
	else if (!(ft_strncmp(rule, "sb", 2)))
		control = sb(swap);
	else if (!(ft_strncmp(rule, "ss", 2)))
		control = ss(swap);
	return (control);
}

void	do_rule(t_swap *swap, char *rule)
{
	int	control;

	control = do_swap(swap, rule);
	if (!(ft_strncmp(rule, "pb", 2)))
		control = pb(&swap);
	else if (!(ft_strncmp(rule, "pa", 2)))
		control = pa(&swap);
	else if (!(ft_strncmp(rule, "ra", 2)))
		control = rx(&swap->stack_a, swap);
	else if (!(ft_strncmp(rule, "rb", 2)))
		control = rx(&swap->stack_b, swap);
	else if (!(ft_strncmp(rule, "rra", 3)))
		control = rrx(&swap->stack_a, swap);
	else if (!(ft_strncmp(rule, "rrb", 3)))
		control = rrx(&swap->stack_b, swap);
	else if (!(ft_strncmp(rule, "rrr", 3)))
		control = rrr(&swap->stack_a, &swap->stack_b, swap);
	else if (!(ft_strncmp(rule, "rr", 2)))
		control = rr(&swap->stack_a, &swap->stack_b, swap);
	if (control)
		print_rule(rule);
}

void	do_rule_no_printing(t_swap *swap, char *rule)
{
	int	control;

	control = do_swap(swap, rule);
	if (!(ft_strncmp(rule, "pb", 2)))
		control = pb(&swap);
	else if (!(ft_strncmp(rule, "pa", 2)))
		control = pa(&swap);
	else if (!(ft_strncmp(rule, "ra", 2)))
		control = rx(&swap->stack_a, swap);
	else if (!(ft_strncmp(rule, "rb", 2)))
		control = rx(&swap->stack_b, swap);
	else if (!(ft_strncmp(rule, "rra", 3)))
		control = rrx(&swap->stack_a, swap);
	else if (!(ft_strncmp(rule, "rrb", 3)))
		control = rrx(&swap->stack_b, swap);
	else if (!(ft_strncmp(rule, "rrr", 3)))
		control = rrr(&swap->stack_a, &swap->stack_b, swap);
	else if (!(ft_strncmp(rule, "rr", 2)))
		control = rr(&swap->stack_a, &swap->stack_b, swap);
}
