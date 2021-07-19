/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAMON <RAMON@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:02:39 by cmarcu            #+#    #+#             */
/*   Updated: 2021/07/19 17:38:39 by RAMON            ###   ########.fr       */
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
}	t_list;

typedef struct s_swap
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		moves;
	int		repeated;
	int		lst_length;
	int		chunk_length;
}	t_swap;

int		ft_atoi(const char *str);
int		ft_isspace(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);

void	push_swap_fill(int argc, char **argv, t_swap *swap);
void	check_for_letters(int i, char **argv);
void	check_repeated(t_swap *swap, t_list *stack_a);
void	free_split(char **temp);

void	ft_lstdelone(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(int));
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);

int		swap_rule(t_swap *swap, t_list *stack);
int		sa(t_swap *swap);
int		sb(t_swap *swap);
int		ss(t_swap *swap);
int		pa(t_swap **swap);
int		pb(t_swap **swap);
int		rx(t_list **head, t_swap *swap);
int		rr(t_list **head_a, t_list **head_b, t_swap *swap);
int		rrx(t_list **head, t_swap *swap);
int		rrr(t_list **head_a, t_list **head_b, t_swap *swap);

int		check_sorted(t_list *lst);

void	push_swap_sorter(t_swap *swap);
void	sort_three(t_swap *swap);

void	sort_more(t_swap *swap);
void	repeat_rule_push(int n, char *str, t_swap **swap);
void	repeat_rule_rotate(int n, char *str, t_swap *swap);
int		min_position(t_list *stack);

void	chunk_algorithm(t_swap *swap);
int		number_of_chunks(int lst_length);
void	copy_stack_to_array(t_list *stack, int *stack_copy);
void	fill_chunk(t_swap *swap, int *chunk, int *stack_copy);
void	push_back(t_swap *swap);
int		max_position(t_list *stack);
void	get_to_top(int pos, t_swap *swap);
void	get_to_top_b(int pos, t_swap *swap);
int		retrieve_position(t_swap *swap, int *chunk, int *stk);

void	print_error(void);
void	f(int n);

void	print_rule(char *rule);
void	do_rule(t_swap *swap, char *rule);
int		do_swap(t_swap *swap, char *rule);

#endif
