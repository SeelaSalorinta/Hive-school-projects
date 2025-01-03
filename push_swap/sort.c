/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:40:08 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/11 18:02:36 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_push_swap *ps)
{
	if (ps->a->array[0] > ps->a->array[1])
		ra(ps);
	free_ps(ps);
	exit(0);
}

static void	sort_three(t_push_swap *ps)
{
	int		first;
	int		second;
	int		third;

	first = ps->a->array[0];
	second = ps->a->array[1];
	third = ps->a->array[2];
	if (first > second && second > third)
	{
		sa(ps);
		rra(ps);
	}
	else if (first > second && first > third && second < third)
		ra(ps);
	else if (first < second && first > third)
		rra(ps);
	else if (first < second && first < third && second > third)
	{
		rra(ps);
		sa(ps);
	}
	else if (first > second && first < third)
		sa(ps);
}

void	sort(t_push_swap *ps)
{
	if (ps->a->size > 3)
	{
		pb(ps);
		if (ps->a->size > 3)
			pb(ps);
	}
	while (ps->a->size > 3)
		cost(ps);
	if (ps->a->size == 3)
		sort_three(ps);
	rotate_biggest_on_top(ps);
	from_b_to_a(ps);
	rotate_smallest_on_top(ps);
}
