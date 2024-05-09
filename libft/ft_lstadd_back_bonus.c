/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:35:21 by ssalorin          #+#    #+#             */
/*   Updated: 2024/04/30 14:08:16 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst && *lst)
	{
		temp = *lst;
		while (temp -> next)
			temp = temp -> next;
		temp -> next = new;
	}
	else if (lst)
		*lst = new;
}
