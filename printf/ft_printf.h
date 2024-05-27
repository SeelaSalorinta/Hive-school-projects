/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:18:32 by ssalorin          #+#    #+#             */
/*   Updated: 2024/05/23 10:00:33 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);

int	ft_print_char(int c);
int	ft_print_s(char *s);
int	ft_print_ptr(unsigned long long ptr);
int	ft_print_nbr(int n);
int	ft_print_unsig(unsigned int n);
int	ft_print_hex(unsigned int n, const char format);

#endif
