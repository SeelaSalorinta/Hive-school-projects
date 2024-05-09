/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:36:07 by ssalorin          #+#    #+#             */
/*   Updated: 2024/05/09 11:15:22 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*s;

	total = count * size;
	if (size > 0 && count > 0 && size != (total / count))
		return (NULL);
	s = (void *)malloc(total);
	if (!s)
		return (NULL);
	ft_bzero(s, total);
	return (s);
}
