/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:02:00 by cmarcu            #+#    #+#             */
/*   Updated: 2021/06/15 16:48:43 by cmarcu           ###   ########.fr       */
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
	if (!lst)
		return ;
	free(lst);
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

void push_swap_fill(int argc, char **argv, t_swap *swap)
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
	ft_lstiter(swap->stack_a, f);
	printf("Number of args: %d\n", argc);
	printf("Number of nums: %d\n", i - 1);
	// Solo para comprobar que push funciona, pero no debería estar aquí esto
	//pb(&swap);
	//pb(&swap);
	//ft_lstiter(swap->stack_a, f);
	//rx(&swap->stack_a, swap);
	//rrr(&swap->stack_a, &swap->stack_b, swap);
	//ft_lstiter(swap->stack_a, f);
	//ft_lstiter(swap->stack_b, f);
}

void	push_swap_sorter(int argc, t_swap *swap)
{
	if (argc == 3)
		sa(swap);
	else if (argc == 4)
		sort_three(swap);
}

void check_if_already_ok(t_list *lst)
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
			exit(1);
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

int main(int argc, char **argv)
{
	t_swap push_swap;

	if (argc < 2)
	 	return (0);
	push_swap_fill(argc, argv, &push_swap);
	check_if_already_ok(push_swap.stack_a);
	push_swap_sorter(argc, &push_swap);
	//push_swap.moves = 0; Hay que inicializarlo en algún lugar??
	//sa(&push_swap);
	ft_lstiter(push_swap.stack_a, f);
	printf("Number of moves: %d", push_swap.moves);
}
