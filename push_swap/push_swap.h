/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:38:39 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/30 15:20:57 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int		*array;
	int		size;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*a;
	t_stack	*b;
	int		rotations_a;
	int		rotations_b;
	int		ra_direc;
	int		rb_direc;
	int		best_ra;
	int		best_rb;
	int		min_cost;
	int		best_index;
	int		best_ra_direc;
	int		best_rb_direc;
	int		best_double_rot;
	int		best_double_dir;
	int		double_rot;
}	t_push_swap;

void	free_ps(t_push_swap *ps);
void	free_split(char **map);
void	checksorted(t_push_swap *ps);
void	sort_two(t_push_swap *ps);
void	sort(t_push_swap *ps);
void	cost(t_push_swap *ps);
void	count_rotations(t_push_swap *ps, int i, int insert_pos);
void	biggest_on_top_of_b(t_push_swap *ps);
void	smallest_on_top_of_a(t_push_swap *ps);
void	from_b_to_a(t_push_swap *ps);
void	rotate_stacks(t_push_swap *ps);
void	rotate_biggest_on_top(t_push_swap *ps);
void	rotate_smallest_on_top(t_push_swap *ps);
int		ft_atoi2(const char *str, int *error);
int		find_smallest_index(t_stack *a);
int		is_valid_number(const char *str);
int		checkdoubles(t_push_swap *ps);
int		find_biggest_index(t_stack *b);
void	print_error(void);

void	pb(t_push_swap *ps);
void	pa(t_push_swap *ps);
void	ra(t_push_swap *ps);
void	rb(t_push_swap *ps);
void	rr(t_push_swap *ps);
void	rra(t_push_swap *ps);
void	rrb(t_push_swap *ps);
void	rrr(t_push_swap *ps);
void	sa(t_push_swap *ps);

#endif
