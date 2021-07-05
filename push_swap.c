/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:02:00 by cmarcu            #+#    #+#             */
/*   Updated: 2021/07/05 17:16:59 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	free_split(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	if (temp)
		free(temp);
}

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
		free_split(temp);
		j++;
	}
	swap->lst_length = ft_lstsize(swap->stack_a);
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
	//printf("Tamaño stack_a: %d\n", ft_lstsize(swap->stack_a));
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
	//printf("Number of moves: %d\n", push_swap.moves);
	//ft_lstiter(push_swap.stack_a, f);
	//printf("Number of moves: %d\n", push_swap.moves);
	//ft_lstiter(push_swap.stack_a, f);
	//system("leaks push_swap");
}
