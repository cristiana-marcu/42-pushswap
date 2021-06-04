/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:02:39 by cmarcu            #+#    #+#             */
/*   Updated: 2021/06/01 20:37:09 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // Null
# include <fcntl.h> // File control: open, read, close
# include <stdlib.h> // Malloc, free
# include <stdio.h> // Printf, scanf
# include <limits.h> // Int min and max values

typedef struct s_list
{
	int				content;
	struct s_list	*next;
} t_list;

typedef struct s_swap
{
	t_list *stack_a;
	t_list *stack_b;
	int moves;
	int repeated;
} t_swap;

int	ft_atoi(const char *str);
void push_swap_fill(int argc, char **argv, t_swap *swap);

#endif
