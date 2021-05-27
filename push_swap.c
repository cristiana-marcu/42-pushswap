/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:02:00 by cmarcu            #+#    #+#             */
/*   Updated: 2021/05/27 16:57:52 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/*void fill_stack(t_swap *swap, int argc, char **argv)
{
	int i;

	i = 1;
	printf("Hey yo\n");
	swap->numbers = (int **)malloc(sizeof(int *) * argc - 1);
	printf("Hey yo\n");
	while (argv[i])
	{
		printf("argv: %s\n", argv[i]);
		swap->numbers[0][i - 1] = ft_atoi(argv[i]);
		printf("Hey yo\n");
		i++;
	}
}*/

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

void	f(int n)
{
	printf("%d\n", n);
}

static int	ft_isspace(char *str)
{
	int	a;

	a = 0;
	while (str[a] == '\t' || str[a] == '\n' || str[a] == '\v'
		|| str[a] == '\f' || str[a] == '\r' || str[a] == ' ')
		a++;
	return (a);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	a;
	int	number;
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
	while (ft_isdigit(str[a]))
	{
		number = number * 10 + (str[a] - '0');
		a++;
	}
	if (is_neg)
		return (-number);
	else
		return (number);
}

int main(int argc, char **argv)
{
	int 	i;
	int 	j;
	int		number;
	// t_swap	*swap;
	t_list *stack_a;
	i = 1;
	number = 0;
	// if (argc < 2)
	// 	return (0);
	// while (argv[i])
	// {
	// 	j = 0;
	// 	while (argv[i][j])
	// 	{
	// 		if (!((argv[i][j] <= '9' && argv[i][j] >= '0')
	// 		|| (j == 0 && argv[i][j] == '-')))
	// 			return (printf("Error\n"));
	// 		j++;
	// 	}
	// 	i++;
	// }
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] <= '9' && argv[i][j] >= '0')
			|| (j == 0 && argv[i][j] == '-')))
				return (printf("Error\n"));
			number = ft_atoi(argv[i]);
			ft_lstadd_back(&stack_a, ft_lstnew(number));
			j++;
		}
		i++;
	}
	ft_lstiter(stack_a, f);
	// printf("im in");
	// swap = malloc(sizeof(t_swap));
	// fill_stack(swap, argc, argv);
	printf("Number of args: %d\n", argc);
	printf("Number of nums: %d", i-1);
}
