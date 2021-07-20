/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:09:01 by cmarcu            #+#    #+#             */
/*   Updated: 2021/07/20 16:31:33 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H

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
void	sa(t_swap *swap);
void	sb(t_swap *swap);
void	ss(t_swap *swap);
void	pa(t_swap **swap);
void	pb(t_swap **swap);
int		rx(t_list **head, t_swap *swap, char *str);
int		rrx(t_list **head, t_swap *swap, char *str);
void	rrr(t_list **head_a, t_list **head_b, t_swap *swap);

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
int		retrieve_position(t_swap *swap, int *chunk, int*stk);

void	print_error(void);
void	f(int n);

int		get_next_line(int fd, char **line);
int		mount_next_line(int re, char **re_acu, char **line);
int		delmem(char **p);
void	ft_bzero(char *s, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);

void	print_rule(char *rule);
void	do_rule(t_swap *swap, char *rule);
void	do_rule_no_printing(t_swap *swap, char *rule);
int		do_swap(t_swap *swap, char *rule);
void	do_swappush_no_print(t_swap *swap, char *line);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 34
# endif

#endif
