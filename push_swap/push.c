/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:37:36 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/11 16:05:06 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_push_swap *ps)
{
	int		i;
	int		element;

	i = 0;
	element = ps->b->array[0];
	while (i < ps->b->size - 1)
	{
		ps->b->array[i] = ps->b->array[i + 1];
		i++;
	}
	ps->b->size--;
	i = ps->a->size;
	while (i > 0)
	{
		ps->a->array[i] = ps->a->array[i - 1];
		i--;
	}
	ps->a->array[0] = element;
	ps->a->size++;
	ft_printf("pa\n");
}

void	pb(t_push_swap *ps)
{
	int		i;
	int		element;

	i = 0;
	element = ps->a->array[0];
	while (i < ps->a->size - 1)
	{
		ps->a->array[i] = ps->a->array[i + 1];
		i++;
	}
	ps->a->size--;
	i = ps->b->size;
	while (i > 0)
	{
		ps->b->array[i] = ps->b->array[i - 1];
		i--;
	}
	ps->b->array[0] = element;
	ps->b->size++;
	ft_printf("pb\n");
}
