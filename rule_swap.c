/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:33:46 by cmarcu            #+#    #+#             */
/*   Updated: 2021/06/09 17:07:27 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// sa | sb | ss -> Intercambiar los primeros 2 elementos en la parte superior de la pila x.
// No hace nada si sólo hay uno o ningún elementos.

int	swap_rule(t_swap *swap, t_list *stack)
{
	int aux;

	if (stack->content && stack->next->content)
	{
		aux = stack->content;
		stack->content = stack->next->content;
		stack->next->content = aux;
		swap->moves += 1;
		return (1);
	}
	return (0);
}

void	sa(t_swap *swap)
{
	if(swap_rule(swap, swap->stack_a))
		write(1, "sa\n", 3);
}

void	sb(t_swap *swap)
{
	if(swap_rule(swap, swap->stack_b))
		write(1, "sb\n", 3);
}

void	ss(t_swap *swap)
{
	int control;

	control = 0;
	if(swap_rule(swap, swap->stack_a))
		control++;
	if(swap_rule(swap, swap->stack_b))
		control++;
	if(control == 2)
		write(1, "ss\n", 3);
}
