/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:39:04 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/11 16:10:16 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_push_swap *ps)
{
	int		i;
	int		temp;

	i = ps->a->size - 1;
	temp = ps->a->array[ps->a->size - 1];
	while (i > 0)
	{
		ps->a->array[i] = ps->a->array[i - 1];
		i--;
	}
	ps->a->array[0] = temp;
	ft_printf("rra\n");
}

void	rrb(t_push_swap *ps)
{
	int		i;
	int		temp;

	i = ps->b->size - 1;
	temp = ps->b->array[ps->b->size - 1];
	while (i > 0)
	{
		ps->b->array[i] = ps->b->array[i - 1];
		i--;
	}
	ps->b->array[0] = temp;
	ft_printf("rrb\n");
}

void	rrr(t_push_swap *ps)
{
	int		i;
	int		temp;

	i = ps->a->size - 1;
	temp = ps->a->array[ps->a->size - 1];
	while (i > 0)
	{
		ps->a->array[i] = ps->a->array[i - 1];
		i--;
	}
	ps->a->array[0] = temp;
	i = ps->b->size - 1;
	temp = ps->b->array[ps->b->size - 1];
	while (i > 0)
	{
		ps->b->array[i] = ps->b->array[i - 1];
		i--;
	}
	ps->b->array[0] = temp;
	ft_printf("rrr\n");
}
