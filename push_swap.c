/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:02:00 by cmarcu            #+#    #+#             */
/*   Updated: 2021/06/24 17:28:20 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void push_swap_fill(int argc, char **argv, t_swap *swap)
{
	int		i;
	int		j;
	int		num;
	char	**temp;

	j = 1;
	while (j < argc)
	{
		temp = ft_split(argv[j], ' ');
		i = 0;
		while (temp[i])
		{
			check_for_letters(i, temp);
			num = ft_atoi(temp[i]);
			swap->repeated = num;
			check_repeated(swap, swap->stack_a);
			ft_lstadd_back(&swap->stack_a, ft_lstnew(num));
			i++;
		}
		j++;
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
		rrx(&swap->stack_a, swap, "rra");
	}
	else if (n1 < n2 && n1 < n3 && n2 > n3) // 1 3 2
	{
		sa(swap);
		rx(&swap->stack_a, swap, "ra");
	}
	else if (n1 > n2 && n1 < n3 && n2 < n3) // 2 1 3
		sa(swap);
	else if (n1 < n2 && n1 > n3 && n2 > n3) // 2 3 1
		rrx(&swap->stack_a, swap, "rra");
	else if (n1 > n2 && n1 > n3 && n2 < n3) // 3 1 2
		rx(&swap->stack_a, swap, "ra");
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
			repeat_rule_rotate(pos, "ra", &aux, swap);
		else if (pos > length / 2)
			repeat_rule_rotate(length - pos, "rra", &aux, swap);
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
		repeat_rule_rotate(pos, "ra", &swap->stack_a, swap);
	else if (pos > swap->lst_length / 2)
		repeat_rule_rotate(swap->lst_length - pos + 1, "rra", &swap->stack_a, swap);
}

void get_to_top_b(int pos, t_swap *swap)
{
	int b_length;

	b_length = ft_lstsize(swap->stack_b);
	if (pos <= b_length / 2)
		repeat_rule_rotate(pos, "rb", &swap->stack_b, swap);
	else if (pos > b_length / 2)
		repeat_rule_rotate(b_length - pos, "rrb", &swap->stack_b, swap);
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
	printf("Tamaño stack_a: %d\n", ft_lstsize(swap->stack_a));
	//printf("Stack_a: %d\n", swap->stack_a->content);
	push_back(swap);
}

int main(int argc, char **argv)
{
	t_swap push_swap;

	if (argc < 2)
	 	return (0);
	push_swap_fill(argc, argv, &push_swap);
	check_sorted(push_swap.stack_a);
	push_swap_sorter(&push_swap);
	printf("Number of moves: %d\n", push_swap.moves);
	//ft_lstiter(push_swap.stack_a, f);
	//printf("Number of moves: %d\n", push_swap.moves);
	ft_lstiter(push_swap.stack_a, f);
}
