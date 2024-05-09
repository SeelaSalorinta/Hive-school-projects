/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:43:59 by ssalorin          #+#    #+#             */
/*   Updated: 2024/05/09 12:07:58 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_stra(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (count);
}

void	ft_copy(char **strings, char const *s, int len, int x)
{
	strings[x][len] = '\0';
	len--;
	while (len >= 0)
	{
		strings[x][len] = s[len];
		len--;
	}
}

void	ft_free(char **strings, int x)
{
	while (x >= 0)
	{
		free(strings[x]);
		x--;
	}
	free(strings);
}

char	**ft_mal(char **strings, char const *s, char c, int i)
{
	int	len;
	int	x;

	len = 0;
	x = 0;
	while (s[i] && x < ft_stra(s, c))
	{
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len != 0)
		{
			strings[x] = (char *)malloc(sizeof(char) * (len + 1));
			if (!strings[x])
			{
				ft_free(strings, x);
				return (NULL);
			}
			ft_copy(strings, &s[i], len, x);
			x++;
			i = i + len;
			len = 0;
		}
		i++;
	}
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		i;
	int		samount;

	i = 0;
	samount = ft_stra(s, c);
	if (!s)
		return (NULL);
	strings = (char **)malloc(sizeof(char *) * (samount + 1));
	if (!strings)
		return (NULL);
	strings = ft_mal(strings, s, c, i);
	strings[samount] = NULL;
	return (strings);
}
