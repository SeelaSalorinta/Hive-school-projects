/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:08:38 by ssalorin          #+#    #+#             */
/*   Updated: 2024/05/09 12:58:28 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_write('-', fd);
		ft_write('2', fd);
		n = 147483648;
	}
	else if (n < 0)
	{
		ft_write('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		n = n % 10;
	}
	if (n < 10)
	{
		ft_write((n + 48), fd);
	}
}
