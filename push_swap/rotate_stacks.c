/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:39:50 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/11 16:19:41 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_smallest_on_top(t_push_swap *ps)
{
	while (ps->a->array[0] != ps->a->array[find_smallest_index(ps->a)])
	{
		if (find_smallest_index(ps->a) <= ps->a->size / 2)
			ra(ps);
		else
			rra(ps);
	}
}

void	rotate_biggest_on_top(t_push_swap *ps)
{
	if (ps->b->size != 0)
	{
		while (ps->b->array[0] != ps->b->array[find_biggest_index(ps->b)])
		{
			if (find_biggest_index(ps->b) <= ps->b->size / 2)
				rb(ps);
			else
				rrb(ps);
		}
	}
}

void	rotate_stacks(t_push_swap *ps)
{
	while (ps->best_double_rot != 0)
	{
		if (ps->best_double_dir == 1)
			rr(ps);
		else if (ps->best_double_dir == 2)
			rrr(ps);
		ps->best_double_rot--;
	}
	while (ps->best_ra != 0)
	{
		if (ps->best_ra_direc == 1)
			ra(ps);
		else if (ps->best_ra_direc == 2)
			rra(ps);
		ps->best_ra--;
	}
	while (ps->best_rb != 0)
	{
		if (ps->best_rb_direc == 1)
			rb(ps);
		else if (ps->best_rb_direc == 2)
			rrb(ps);
		ps->best_rb--;
	}
}
