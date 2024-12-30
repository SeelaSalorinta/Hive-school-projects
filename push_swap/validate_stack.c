/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:40:45 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/11 17:14:35 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *str)
{
	int		i;
	int		has_digit;

	i = 0;
	has_digit = 0;
	if (!str || !str[i])
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		has_digit = 1;
		i++;
	}
	if (!has_digit)
		return (1);
	return (0);
}

void	checksorted(t_push_swap *ps)
{
	int		i;

	i = 0;
	while (i < ps->a->size - 1)
	{
		if (ps->a->array[i] > ps->a->array[i + 1])
			return ;
		i++;
	}
	free_ps(ps);
	exit(0);
}

int	checkdoubles(t_push_swap *ps)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (!ps->a || !ps->a->array || ps->a->size < 2)
		return (1);
	while (i < ps->a->size - 1)
	{
		x = i + 1;
		while (x < ps->a->size)
		{
			if (ps->a->array[i] == ps->a->array[x])
				return (1);
			x++;
		}
		i++;
	}
	return (0);
}
