/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:36:14 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/11 18:00:48 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	count_double_rot(t_push_swap *ps)
{
	int		double_rot;
	int		double_dir;
	int		cost;

	double_rot = 0;
	double_dir = 0;
	while (ps->rotations_a != 0 && ps->rotations_b != 0
		&& ps->ra_direc == ps->rb_direc)
	{
		double_rot++;
		ps->rotations_a--;
		ps->rotations_b--;
		double_dir = ps->ra_direc;
	}
	cost = ps->rotations_a + ps->rotations_b + double_rot + 1;
	if (cost < ps->min_cost)
	{
		ps->min_cost = cost;
		ps->best_ra = ps->rotations_a;
		ps->best_rb = ps->rotations_b;
		ps->best_ra_direc = ps->ra_direc;
		ps->best_rb_direc = ps->rb_direc;
		ps->best_double_rot = double_rot;
		ps->best_double_dir = double_dir;
	}
}

void	count_rotations(t_push_swap *ps, int i, int insert_pos)
{
	ps->rotations_a = 0;
	ps->rotations_b = 0;
	if (i <= ps->a->size / 2)
	{
		ps->rotations_a = i;
		ps->ra_direc = 1;
	}
	else
	{
		ps->rotations_a = ps->a->size - i;
		ps->ra_direc = 2;
	}
	if (insert_pos < ps->b->size / 2)
	{
		ps->rotations_b = insert_pos;
		ps->rb_direc = 1;
	}
	else
	{
		ps->rotations_b = ps->b->size - insert_pos;
		ps->rb_direc = 2;
	}
	count_double_rot(ps);
}
