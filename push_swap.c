/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:02:00 by cmarcu            #+#    #+#             */
/*   Updated: 2021/06/21 19:27:58 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(*result));
	if (!result)
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst)
	{
		if (*alst)
			new->next = *alst;
		*alst = new;
	}
}

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

void	ft_lstdelone(t_list *lst)
{
	if (lst)
		free(lst);
}

int	ft_lstsize(t_list *lst)
{
	int	result;

	result = 0;
	while (lst)
	{
		lst = lst->next;
		result++;
	}
	return (result);
}

void	f(int n)
{
	printf("%d\n", n);
}

int	ft_isspace(char *str)
{
	int	a;

	a = 0;
	while (str[a] == '\t' || str[a] == '\n' || str[a] == '\v'
		|| str[a] == '\f' || str[a] == '\r' || str[a] == ' ')
		a++;
	return (a);
}

void print_error()
{
		printf("Error\n");
		exit(1);
}

int	ft_atoi(const char *str)
{
	int	a;
	long number;
	int	is_neg;

	a = ft_isspace((char *)str);
	is_neg = 0;
	number = 0;
	if (str[a] == '-')
	{
		a++;
		is_neg = 1;
	}
	else if (str[a] == '+')
		a++;
	while (str[a] >= '0' && str[a] <= '9')
	{
		number = number * 10 + (str[a] - '0');
		a++;
	}
	if ((is_neg && -number < INT_MIN) || number > INT_MAX)
		print_error();
	if (is_neg)
		return (-number);
	else
		return (number);
}

void	check_repeated(t_swap *swap, t_list *stack_a)
{
	t_list *ptr;

	if (stack_a)
	{
		while (stack_a)
		{
			if (stack_a->content == swap->repeated)
				print_error();
			ptr = stack_a->next;
			stack_a = ptr;
		}
	}
}

void	check_for_letters(int i, char **argv)
{
	int j;

	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] <= '9' && argv[i][j] >= '0')
			|| (j == 0 && argv[i][j] == '-') || (j == 0 && argv[i][j] == '+')))
				print_error();
			j++;
		}
		i++;
	}
}

void push_swap_fill(char **argv, t_swap *swap)
{
	int 	i;
	int 	j;
	int		num;

	i = 1;
	while (argv[i])
	{
		j = 0;
		check_for_letters(i, argv);
		num = ft_atoi(argv[i]);
		swap->repeated = num;
		check_repeated(swap, swap->stack_a);
		ft_lstadd_back(&swap->stack_a, ft_lstnew(num));
		i++;
	}
	swap->lst_length = ft_lstsize(swap->stack_a);
}

void	push_swap_sorter(t_swap *swap)
{
	if (swap->lst_length == 2)
		sa(swap);
	else if (swap->lst_length == 3)
		sort_three(swap);
	else if (swap->lst_length <= 50)
		sort_more(swap);
	else
	{
		swap->lst_length = ft_lstsize(swap->stack_a);
		swap->chunk_length = swap->lst_length / number_of_chunks(swap->lst_length);
		chunk_algorithm(swap);
	}
}

void check_sorted(t_list *lst)
{
	int		n;
	t_list	*next;

	if (lst)
	{
		while (lst)
		{
			n = lst->content;
			next = lst->next;
			if (next)
				if (n > next->content)
					return ;
			lst = next;
		}
		if (lst == NULL)
			exit(1); //TODO A good exit program function
	}
}

void	sort_three(t_swap *swap)
{
	int n1;
	int n2;
	int n3;

	n1 = swap->stack_a->content;
	n2 = swap->stack_a->next->content;
	n3 = swap->stack_a->next->next->content;
	if (n1 > n2 && n1 > n3 && n2 > n3) // 3 2 1
	{
		sa(swap);
		rrx(&swap->stack_a, swap);
	}
	else if (n1 < n2 && n1 < n3 && n2 > n3) // 1 3 2
	{
		sa(swap);
		rx(&swap->stack_a, swap);
	}
	else if (n1 > n2 && n1 < n3 && n2 < n3) // 2 1 3
		sa(swap);
	else if (n1 < n2 && n1 > n3 && n2 > n3) // 2 3 1
		rrx(&swap->stack_a, swap);
	else if (n1 > n2 && n1 > n3 && n2 < n3) // 3 1 2
		rx(&swap->stack_a, swap);
}

int min_position(t_list *stack)
{
	t_list *aux;
	int min;
	int pos;
	int i;

	aux = stack;
	min = aux->content;
	pos = 0;
	i = 0;
	while (aux)
	{
		if (min > aux->content)
		{
			min = aux->content;
			pos = i;
		}
		i++;
		aux = aux->next;
	}
	return (pos);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	while (n && s1[a] != '\0' && s1[a] == s2[a])
	{
		a++;
		--n;
	}
	if (n == 0)
		return (0);
	else
		return ((int)(unsigned char)(s1[a]) - (int)(unsigned char)(s2[a]));
}

void repeat_rule_rotate(int n, char *str, t_list **head, t_swap *swap)
{
	int i;

	i = 0;
	if (!(ft_strncmp(str, "rx", 2)))
	{
		while (i < n)
		{
			rx(head, swap);
			i++;
		}
	}
	else if (!(ft_strncmp(str, "rrx", 3)))
	{
		while (i < n)
		{
			rrx(head, swap);
			i++;
		}
	}
}

void repeat_rule_push(int n, char *str, t_swap **swap)
{
	int i;

	i = 0;
	if (!(ft_strncmp(str, "pa", 2)))
	{
		while (i < n)
		{
			pa(swap);
			i++;
		}
	}
	else if (!(ft_strncmp(str, "pb", 2)))
	{
		while (i < n)
		{
			pb(swap);
			i++;
		}
	}
}

void	sort_more(t_swap *swap)
{
	int length;
	int j;
	int pos;
	t_list *aux;

	j = -1;
	aux = swap->stack_a;
	while (swap->lst_length - ++j > 3)
	{
		pos = min_position(aux);
		length = ft_lstsize(swap->stack_a);
		if (pos <= length / 2)
			repeat_rule_rotate(pos, "rx", &aux, swap);
		else if (pos > length / 2)
			repeat_rule_rotate(length - pos, "rrx", &aux, swap);
		swap->stack_a = aux;
		pb(&swap);
		aux = swap->stack_a;
	}
	sort_three(swap);
	repeat_rule_push(ft_lstsize(swap->stack_b), "pa", &swap);
}

int number_of_chunks(int lst_length)
{
	return ((lst_length + 233.333333) / 66.666666);
}

void fill_chunk(t_swap *swap, int *chunk, int *stack_copy)
{
	int j;
	int i;
	int chunk_length;

	chunk_length = swap->lst_length / number_of_chunks(swap->lst_length);
	j = 1;
	chunk[0] = stack_copy[min_position(swap->stack_a)];
	while (j < chunk_length)
	{
		chunk[j] = INT_MAX;
		i = 0;
		while (i < swap->lst_length)
		{
			if ((stack_copy[i] < chunk[j]) && (stack_copy[i] > chunk[j - 1]))
				chunk[j] = stack_copy[i];
			i++;
		}
		j++;
	}
}

void copy_stack_to_array(t_list *stack, int *stack_copy)
{
	t_list *aux;
	int i;

	i = 0;
	aux = stack;
	while (aux)
	{
		stack_copy[i] = aux->content;
		i++;
		aux = aux->next;
	}
}

int retrieve_position(t_swap *swap, int *chunk, int*stack)
{
	int i;
	int hold_first;
	int hold_second;
	int lst_length;

	lst_length = ft_lstsize(swap->stack_a);
	i = -1;
	hold_first = 0;
	hold_second = lst_length - 1;
	while (++i < lst_length / 2)
	{
		if ((stack[i] >= chunk[0]) && (stack[i] <= chunk[swap->chunk_length - 1]))
		{
			hold_first = i;
			break ;
		}
	}
	i = lst_length;
	while (--i >= lst_length / 2)
	{
		if ((stack[i] >= chunk[0]) && (stack[i] <= chunk[swap->chunk_length - 1]))
		{
			hold_second = i;
			break ;
		}
	}
	// Fix return values 
	if (((hold_first < swap->lst_length - hold_second) && hold_second >= 0 && hold_first >= 0) || hold_second > swap->lst_length)
		return (hold_first);
	else
		return (hold_second);
}

void get_to_top(int pos, t_swap *swap)
{
	if (pos <= swap->lst_length / 2)
		repeat_rule_rotate(pos, "rx", &swap->stack_a, swap);
	else if (pos > swap->lst_length / 2)
		repeat_rule_rotate(swap->lst_length - pos + 1, "rrx", &swap->stack_a, swap);
}

void get_to_top_b(int pos, t_swap *swap)
{
	int b_length;

	b_length = ft_lstsize(swap->stack_b);
	if (pos <= b_length / 2)
		repeat_rule_rotate(pos, "rx", &swap->stack_b, swap);
	else if (pos > b_length / 2)
		repeat_rule_rotate(b_length - pos, "rrx", &swap->stack_b, swap);
}

int max_position(t_list *stack)
{
	t_list *aux;
	int max;
	int pos;
	int i;

	aux = stack;
	max = aux->content;
	pos = 0;
	i = 0;
	while (aux)
	{
		if (max < aux->content)
		{
			max = aux->content;
			pos = i;
		}
		i++;
		aux = aux->next;
	}
	return (pos);
}

void push_back(t_swap *swap)
{
	int position;
	int i;
	int b_length;

	b_length = ft_lstsize(swap->stack_b);
	i = 0;
	while (i < b_length)
	{
		position = max_position(swap->stack_b);
		get_to_top_b(position, swap);
		pa(&swap);
		i++;
	}
}

void chunk_algorithm(t_swap *swap)
{
	int *stack_copy;
	int *chunk;
	int position;
	int i;
	int j;

	j = 0;
	while (j < number_of_chunks(swap->lst_length))
	{
		stack_copy = (int*)malloc(sizeof(int) * swap->lst_length);
		chunk = (int*)malloc(sizeof(int) * swap->chunk_length);
		copy_stack_to_array(swap->stack_a, stack_copy);
		fill_chunk(swap, chunk, stack_copy);
		i = 0;
		while (i < swap->chunk_length)
		{
			copy_stack_to_array(swap->stack_a, stack_copy);
			position = retrieve_position(swap, chunk, stack_copy);
			get_to_top(position, swap);
			pb(&swap);
			i++;
		}
		free(stack_copy);
		free(chunk);
		j++;
	}
	push_back(swap);
}

int main(int argc, char **argv)
{
	t_swap push_swap;

	if (argc < 2)
	 	return (0);
	push_swap_fill(argv, &push_swap);
	check_sorted(push_swap.stack_a);
	push_swap_sorter(&push_swap);
	//printf("Number of moves: %d\n", push_swap.moves);
	//ft_lstiter(push_swap.stack_a, f);
}
