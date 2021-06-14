/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:02:39 by cmarcu            #+#    #+#             */
/*   Updated: 2021/06/14 17:14:48 by cmarcu           ###   ########.fr       */
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
int	ft_isspace(char *str);

void push_swap_fill(int argc, char **argv, t_swap *swap);
void	check_for_letters(int i, char **argv);
void	check_repeated(t_swap *swap, t_list *stack_a);

void	ft_lstdelone(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(int));
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);

int	swap_rule(t_swap *swap, t_list *stack);
void	sa(t_swap *swap);
void	sb(t_swap *swap);
void	ss(t_swap *swap);
void	pa(t_swap **swap);
void	pb(t_swap **swap);
void rx(t_list **head, t_swap *swap);

void print_error();

#endif
