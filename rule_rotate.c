/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:13:16 by cmarcu            #+#    #+#             */
/*   Updated: 2021/06/14 17:18:28 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void rx(t_list **head, t_swap *swap)
{
	t_list *aux;
	t_list *first;
	t_list *last;

	aux = *head;
	if (!(aux && aux->next))
		return ;
	first = aux;
	aux = aux->next;
	last = aux;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*head = aux;
	swap->moves += 1;
	write(1, "ra\n", 3);
}

void rr(t_list **head_a, t_list **head_b, t_swap *swap)
{
	rx(head_a, swap);
	rx(head_b, swap);
}
