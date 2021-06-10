/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:13:16 by cmarcu            #+#    #+#             */
/*   Updated: 2021/06/10 19:59:54 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void rx(t_list **head)
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
	write(1, "ra\n", 3);
}
