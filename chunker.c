/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAMON <RAMON@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:15:04 by cmarcu            #+#    #+#             */
/*   Updated: 2021/07/19 18:48:31 by RAMON            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap_checker.h"

void	fill_chunk(t_swap *swap, int *chunk, int *stack_copy)
{
	int	j;
	int	i;
	int	chunk_length;

	chunk_length = swap->chunk_length;
	j = 1;
	chunk[0] = stack_copy[min_position(swap->stack_a)];
	while (j < chunk_length)
	{
		chunk[j] = INT_MAX;
		i = 0;
		while (i < swap->lst_length)
		{
			if ((stack_copy[i] < chunk[j]) && (stack_copy[i] > chunk[j - 1]))
				chunk[j] = stack_copy[i];
			i++;
		}
		j++;
	}
}

void	copy_stack_to_array(t_list *stack, int *stack_copy)
{
	t_list	*aux;
	int		i;

	i = 0;
	aux = stack;
	while (aux)
	{
		stack_copy[i] = aux->content;
		i++;
		aux = aux->next;
	}
}

int	retrieve_position(t_swap *swap, int *chunk, int *stk)
{
	int	i;
	int	hold_first;
	int	hold_second;
	int	lst_length;

	lst_length = ft_lstsize(swap->stack_a);
	i = -1;
	hold_first = -1;
	hold_second = 0;
	while (++i < lst_length / 2 && hold_first == -1)
	{
		if ((stk[i] >= chunk[0]) && (stk[i] <= chunk[swap->chunk_length - 1]))
			hold_first = i;
	}
	i = lst_length;
	while (--i >= lst_length / 2 && hold_second == 0)
	{
		if ((stk[i] >= chunk[0]) && (stk[i] <= chunk[swap->chunk_length - 1]))
			hold_second = i;
	}
	if (((hold_first < swap->lst_length - hold_second) && hold_second >= 0
			&& hold_first >= 0) || hold_second > swap->lst_length)
		return (hold_first);
	else
		return (hold_second);
}

void	get_to_top(int pos, t_swap *swap)
{
	if (pos <= swap->lst_length / 2)
		repeat_rule_rotate(pos, "ra", swap);
	else if (pos > swap->lst_length / 2)
		repeat_rule_rotate(swap->lst_length - pos + 1, "rra", swap);
}

void	get_to_top_b(int pos, t_swap *swap)
{
	int	b_length;

	b_length = ft_lstsize(swap->stack_b);
	if (pos <= b_length / 2)
		repeat_rule_rotate(pos, "rb", swap);
	else if (pos > b_length / 2)
		repeat_rule_rotate(b_length - pos, "rrb", swap);
}
