/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_other_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAMON <RAMON@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:58:03 by RAMON             #+#    #+#             */
/*   Updated: 2021/07/19 16:27:43 by RAMON            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	number_of_chunks(int lst_length)
{
	return ((lst_length + 233.333333) / 66.666666);
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
