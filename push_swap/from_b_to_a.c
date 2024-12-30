/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:51:44 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/11 18:01:28 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_if_smallest_in_a(t_stack *a, int number)
{
	int		i;
	int		min_index;

	i = 0;
	min_index = 0;
	while (i < a->size && a->array[i] > number)
	{
		if (a->array[i] < a->array[min_index])
			min_index = i;
		i++;
	}
	if (i == a->size)
		return (min_index);
	return (-1);
}

static int	check_if_biggest_in_a(t_stack *a, int number)
{
	int		i;

	i = 0;
	while (i < a->size && a->array[i] < number)
		i++;
	if (i == a->size)
		return (find_smallest_index(a));
	return (-1);
}

static int	find_insert_position_in_a(t_stack *a, int number)
{
	int		i;

	i = -1;
	if (a->size == 0)
		return (0);
	i = check_if_biggest_in_a(a, number);
	if (i != -1)
		return (i);
	i = check_if_smallest_in_a(a, number);
	if (i != -1)
		return (i);
	if (number < a->array[0] && number > a->array[a->size - 1])
		return (0);
	i = 1;
	while (i < a->size)
	{
		if (a->array[i - 1] < number && a->array[i] > number)
			return (i);
		i++;
	}
	return (a->size);
}

static void	rotate_a(t_push_swap *ps, int target_pos_in_a)
{
	if (target_pos_in_a < ps->a->size / 2)
	{
		while (target_pos_in_a > 0)
		{
			ra(ps);
			target_pos_in_a--;
		}
	}
	else
	{
		while (target_pos_in_a < ps->a->size)
		{
			rra(ps);
			target_pos_in_a++;
		}
	}
}

void	from_b_to_a(t_push_swap *ps)
{
	int		target_pos_in_a;

	while (ps->b->size > 0)
	{
		target_pos_in_a = find_insert_position_in_a(ps->a, ps->b->array[0]);
		if (target_pos_in_a != 0)
			rotate_a(ps, target_pos_in_a);
		pa(ps);
	}
}
