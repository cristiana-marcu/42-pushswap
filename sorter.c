/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:12:54 by cmarcu            #+#    #+#             */
/*   Updated: 2021/07/06 18:07:18 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	push_swap_sorter(t_swap *swap)
{
	if (swap->lst_length == 2)
		do_rule(swap, "sa");
	else if (swap->lst_length == 3)
		sort_three(swap);
	else if (swap->lst_length <= 50)
		sort_more(swap);
	else
	{
		swap->lst_length = ft_lstsize(swap->stack_a);
		swap->chunk_length = (swap->lst_length
				/ number_of_chunks(swap->lst_length)) + 1;
		chunk_algorithm(swap);
	}
}

void	sort_three(t_swap *swap)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = swap->stack_a->content;
	n2 = swap->stack_a->next->content;
	n3 = swap->stack_a->next->next->content;
	if (n1 > n2 && n1 > n3 && n2 > n3)
	{
		do_rule(swap, "sa");
		do_rule(swap, "rra");
	}
	else if (n1 < n2 && n1 < n3 && n2 > n3)
	{
		do_rule(swap, "sa");
		do_rule(swap, "ra");
	}
	else if (n1 > n2 && n1 < n3 && n2 < n3)
		do_rule(swap, "sa");
	else if (n1 < n2 && n1 > n3 && n2 > n3)
		do_rule(swap, "rra");
	else if (n1 > n2 && n1 > n3 && n2 < n3)
		do_rule(swap, "ra");
}

int	min_position(t_list *stack)
{
	t_list	*aux;
	int		min;
	int		pos;
	int		i;

	aux = stack;
	if (aux)
		min = aux->content;
	pos = 0;
	i = 0;
	while (aux)
	{
		if (min > aux->content)
		{
			min = aux->content;
			pos = i;
		}
		i++;
		aux = aux->next;
	}
	return (pos);
}

void	sort_more(t_swap *swap)
{
	int		length;
	int		j;
	int		pos;
	t_list	*aux;

	j = -1;
	aux = swap->stack_a;
	while (swap->lst_length - ++j > 3)
	{
		pos = min_position(aux);
		length = ft_lstsize(swap->stack_a);
		if (pos <= length / 2)
			repeat_rule_rotate(pos, "ra", swap);
		else if (pos > length / 2)
			repeat_rule_rotate(length - pos, "rra", swap);
		do_rule(swap, "pb");
		aux = swap->stack_a;
	}
	sort_three(swap);
	repeat_rule_push(ft_lstsize(swap->stack_b), "pa", &swap);
}
