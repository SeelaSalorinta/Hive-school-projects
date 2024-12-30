/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:35:52 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/12 17:45:59 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_if_smallest_in_b(t_stack *b, int number)
{
	int		i;
	int		min_index;

	i = 0;
	min_index = 0;
	while (i < b->size && b->array[i] > number)
	{
		if (b->array[i] <= b->array[min_index])
			min_index = i;
		i++;
	}
	if (i == b->size)
		return (find_biggest_index(b));
	return (-1);
}

static int	check_if_biggest_in_b(t_stack *b, int number)
{
	int		i;
	int		max_index;

	i = 0;
	max_index = 0;
	while (i < b->size && b->array[i] < number)
	{
		if (b->array[i] > b->array[max_index] && i < b->size)
			max_index = i;
		i++;
	}
	if (i == b->size)
		return (max_index);
	return (-1);
}

static int	find_insert_position_in_b(t_stack *b, int number)
{
	int		i;

	i = -1;
	if (b->size == 0)
		return (0);
	i = check_if_biggest_in_b(b, number);
	if (i != -1)
		return (i);
	i = check_if_smallest_in_b(b, number);
	if (i != -1)
		return (i);
	if (number > b->array[0] && number < b->array[b->size - 1])
		return (0);
	i = 1;
	while (i < b->size)
	{
		if (number < b->array[i - 1] && number > b->array[i])
			return (i);
		i++;
	}
	return (b->size - 1);
}

void	cost(t_push_swap *ps)
{
	int	i;
	int	insert_pos;

	i = 0;
	ps->min_cost = INT_MAX;
	while (i < ps->a->size)
	{
		insert_pos = find_insert_position_in_b(ps->b, ps->a->array[i]);
		count_rotations(ps, i, insert_pos);
		if (ps->min_cost == 1)
			break ;
		i++;
	}
	if (ps->min_cost > 1)
		rotate_stacks(ps);
	pb(ps);
}
