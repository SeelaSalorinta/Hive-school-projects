/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:40:27 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/11 16:21:27 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push_swap *ps)
{
	int		temp;

	temp = ps->a->array[0];
	ps->a->array[0] = ps->a->array[1];
	ps->a->array[1] = temp;
	ft_printf("sa\n");
}
