/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:15:55 by cmarcu            #+#    #+#             */
/*   Updated: 2021/06/09 18:19:37 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// pa | pb | pp -> Toma el primer elemento en la parte superior de a ó b y ponerlo en la
// parte superior de a ó b. No hace nada si a ó b está vacío.

void		pb(t_swap **head)
{
	t_list	*tmp;
	t_list	*to;
	t_list	*from;

	to = (*head)->stack_b;
	from = (*head)->stack_a;
	if (!from)
		return ;
	tmp = from;
	from = from->next;
	(*head)->stack_a = from;
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		(*head)->stack_b = to;
	}
	else
	{
		tmp->next = to;
		(*head)->stack_b = tmp;
	}
	(*head)->moves += 1;
	write(1, "pb\n", 3);
}

void		pa(t_swap **head)
{
	t_list	*tmp;
	t_list	*to;
	t_list	*from;

	to = (*head)->stack_a;
	from = (*head)->stack_b;
	if (!from)
		return ;
	tmp = from;
	from = from->next;
	(*head)->stack_b = from;
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		(*head)->stack_a = to;
	}
	else
	{
		tmp->next = to;
		(*head)->stack_a = tmp;
	}
	(*head)->moves += 1;
	write(1, "pa\n", 3);
}
