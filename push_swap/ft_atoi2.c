/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:52:38 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/11 17:58:49 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error_found(int sign, int *error)
{
	*error = 1;
	if (sign == -1)
		return (0);
	return (-1);
}

int	ft_atoi2(const char *str, int *error)
{
	int		a;
	int		sign;
	long	nbr;

	a = 0;
	sign = 1;
	nbr = 0;
	if (!ft_strncmp(str, "-2147483648", 11))
		return (INT_MIN);
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == 32)
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			sign = -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		nbr = nbr * 10 + (str[a] - '0');
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (error_found(sign, error));
		a++;
	}
	return (sign * nbr);
}
