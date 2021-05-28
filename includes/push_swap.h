/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:02:39 by cmarcu            #+#    #+#             */
/*   Updated: 2021/05/28 11:57:50 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // Null
# include <fcntl.h> // File control: open, read, close
# include <stdlib.h> // Malloc, free
# include <stdio.h> // Printf, scanf

typedef struct s_swap
{
	int		**numbers;
} t_swap;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
} t_list;

int	ft_atoi(const char *str);

#endif
