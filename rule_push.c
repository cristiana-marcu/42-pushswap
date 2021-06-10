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

void	pa(t_swap **swap)
{
	if((*swap)->stack_b)
	{
		ft_lstadd_front(&(*swap)->stack_a, ft_lstnew((*swap)->stack_b->content));
		ft_lstdelone((*swap)->stack_b);
		if ((*swap)->stack_b->next)
			(*swap)->stack_b = (*swap)->stack_b->next;
		else
			(*swap)->stack_b = NULL;
		(*swap)->moves += 1;
		write(1, "pa\n", 3);
	}
}

void	pb(t_swap **swap)
{
	if((*swap)->stack_a)
	{
		ft_lstadd_front(&(*swap)->stack_b, ft_lstnew((*swap)->stack_a->content));
		ft_lstdelone((*swap)->stack_a);
		if ((*swap)->stack_a->next)
			(*swap)->stack_a = (*swap)->stack_a->next;
		else
			(*swap)->stack_a = NULL;
		(*swap)->moves += 1;
		write(1, "pb\n", 3);
	}
}
