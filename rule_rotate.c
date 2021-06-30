/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:13:16 by cmarcu            #+#    #+#             */
/*   Updated: 2021/06/24 14:06:54 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	rx(t_list **head, t_swap *swap, char *str)
{
	t_list	*aux;
	t_list	*first;
	t_list	*last;

	aux = *head;
	if (!(aux && aux->next))
		return (0);
	first = aux;
	aux = aux->next;
	last = aux;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*head = aux;
	swap->moves += 1;
	if (!(ft_strncmp(str, "ra", 2)))
		write(1, "ra\n", 3);
	else if (!(ft_strncmp(str, "rb", 2)))
		write(1, "rb\n", 3);
	return (1);
}

void	rr(t_list **head_a, t_list **head_b, t_swap *swap)
{
	rx(head_a, swap, "ra");
	rx(head_b, swap, "rb");
}

int	rrx(t_list **head, t_swap *swap, char *str)
{
	t_list	*aux;
	t_list	*previous;
	t_list	*last;

	aux = *head;
	if (!(aux && aux->next))
		return (0);
	last = aux;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	last->next = aux;
	previous->next = NULL;
	*head = last;
	swap->moves += 1;
	if (!(ft_strncmp(str, "rra", 3)))
		write(1, "rra\n", 4);
	else if (!(ft_strncmp(str, "rrb", 3)))
		write(1, "rrb\n", 4);
	return (1);
}

void	rrr(t_list **head_a, t_list **head_b, t_swap *swap)
{
	rrx(head_a, swap, "rra");
	rrx(head_b, swap, "rrb");
}

void	repeat_rule_rotate(int n, char *str, t_list **head, t_swap *swap)
{
	int	i;

	i = 0;
	if (!(ft_strncmp(str, "ra", 2)))
	{
		while (i < n)
		{
			rx(head, swap, "ra");
			i++;
		}
	}
	else if (!(ft_strncmp(str, "rra", 3)))
	{
		while (i < n)
		{
			rrx(head, swap, "rra");
			i++;
		}
	}
	else if (!(ft_strncmp(str, "rb", 2)))
	{
		while (i < n)
		{
			rx(head, swap, "rb");
			i++;
		}
	}
	else if (!(ft_strncmp(str, "rrb", 3)))
	{
		while (i < n)
		{
			rrx(head, swap, "rrb");
			i++;
		}
	}
}
