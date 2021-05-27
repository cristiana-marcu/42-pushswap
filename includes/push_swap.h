/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:02:39 by cmarcu            #+#    #+#             */
/*   Updated: 2021/05/27 16:18:42 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

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
