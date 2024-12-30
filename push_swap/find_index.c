/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:36:31 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/11 15:36:34 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest_index(t_stack *b)
{
	int		biggest_index;
	int		i;

	biggest_index = 0;
	i = 1;
	while (i < b->size)
	{
		if (b->array[i] > b->array[biggest_index])
			biggest_index = i;
		i++;
	}
	return (biggest_index);
}

int	find_smallest_index(t_stack *a)
{
	int		smallest_index;
	int		i;

	smallest_index = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->array[i] < a->array[smallest_index])
			smallest_index = i;
		i++;
	}
	return (smallest_index);
}
