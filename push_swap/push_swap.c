/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:50:02 by ssalorin          #+#    #+#             */
/*   Updated: 2025/01/03 14:11:50 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_stack(t_stack *a, t_stack *b, int count, char **argv)
{
	int		i;
	int		error;

	i = 0;
	error = 0;
	a->array = NULL;
	b->array = NULL;
	a->array = malloc(sizeof(int) * count);
	if (!a->array)
		return (1);
	a->size = count;
	b->array = malloc(sizeof(int) * (a->size));
	if (!b->array)
		return (1);
	b->size = 0;
	while (i < count)
	{
		a->array[i] = ft_atoi2(argv[i], &error);
		if (error == 1)
			return (1);
		i++;
	}
	return (0);
}

static void	form_stacks(t_push_swap *ps, char **args, int count, int argc)
{
	int		error;

	error = 0;
	ps->a = malloc(sizeof(t_stack));
	if (!ps->a)
		exit(1);
	ps->b = malloc(sizeof(t_stack));
	if (!ps->b)
	{
		free(ps->a);
		exit(1);
	}
	if (argc == 2)
	{
		error = init_stack(ps->a, ps->b, count, args);
		free_split(args);
	}
	else
		error = init_stack(ps->a, ps->b, count - 1, &args[1]);
	if (error == 1)
	{
		free_ps(ps);
		print_error();
	}
}

static int	check_args(char **args, int argc, int i)
{
	while (args[i])
	{
		if (is_valid_number(args[i]) == 1)
		{
			if (argc == 2)
				free_split(args);
			print_error();
		}
		i++;
	}
	return (i);
}

static void	form_args(t_push_swap *ps, int argc, char **argv)
{
	int		starting_i;
	char	**args;
	int		count;

	starting_i = 0;
	args = NULL;
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		args = ft_split(argv[1], ' ');
		if (!args)
			print_error();
	}
	if (argc > 2)
	{
		starting_i = 1;
		args = argv;
	}
	count = check_args(args, argc, starting_i);
	form_stacks(ps, args, count, argc);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc < 2)
		return (1);
	form_args(&ps, argc, argv);
	if (ps.a->size == 1)
	{
		free_ps(&ps);
		return (0);
	}
	if (checkdoubles(&ps) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		free_ps(&ps);
		return (1);
	}
	checksorted(&ps);
	if (ps.a->size == 2)
		sort_two(&ps);
	sort(&ps);
	free_ps(&ps);
	return (0);
}
