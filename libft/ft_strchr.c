/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:56:22 by ssalorin          #+#    #+#             */
/*   Updated: 2024/05/09 12:10:16 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	mychar;
	size_t			i;

	mychar = c;
	i = 0;
	while (s[i] != mychar && s[i])
		i++;
	if (s[i] == mychar)
		return ((char *)s + i);
	return (0);
}
