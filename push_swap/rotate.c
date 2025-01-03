/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:39:22 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/11 16:15:42 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_push_swap *ps)
{
	int		i;
	int		temp;

	i = 0;
	temp = ps->a->array[0];
	while (i < (ps->a->size - 1))
	{
		ps->a->array[i] = ps->a->array[i + 1];
		i++;
	}
	ps->a->array[ps->a->size - 1] = temp;
	ft_printf("ra\n");
}

void	rb(t_push_swap *ps)
{
	int		i;
	int		temp;

	i = 0;
	temp = ps->b->array[0];
	while (i < (ps->b->size - 1))
	{
		ps->b->array[i] = ps->b->array[i + 1];
		i++;
	}
	ps->b->array[ps->b->size - 1] = temp;
	ft_printf("rb\n");
}

void	rr(t_push_swap *ps)
{
	int		i;
	int		temp;

	i = 0;
	temp = ps->a->array[0];
	while (i < (ps->a->size - 1))
	{
		ps->a->array[i] = ps->a->array[i + 1];
		i++;
	}
	ps->a->array[ps->a->size - 1] = temp;
	i = 0;
	temp = ps->b->array[0];
	while (i < (ps->b->size - 1))
	{
		ps->b->array[i] = ps->b->array[i + 1];
		i++;
	}
	ps->b->array[ps->b->size - 1] = temp;
	ft_printf("rr\n");
}
