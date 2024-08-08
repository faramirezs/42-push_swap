/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:26:02 by alramire          #+#    #+#             */
/*   Updated: 2024/08/08 14:59:57 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**norm_input(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		exit(0);
	else if (argc == 2)
		argv = norm_two_args(argc, argv);
	else if (argc >= 3)
	{
		i = 1;
		while (i < argc)
		{
			if (is_not_integer(argv[i]) || out_of_limit(argv[i]))
				exit(write(2, "Error\n", 6));
			i++;
		}
	}
	else
		exit(write(2, "Error\n", 6));
	return (argv);
}

char	**norm_two_args(int argc, char **argv)
{
	int		i;
	char	**split;

	split = ft_split(argv[1], ' ');
	if (!split || !*split)
		exit(write(2, "Error\n", 6));
	i = 0;
	while (split[i])
	{
		if (is_not_integer(split[i]) || out_of_limit(split[i]))
		{
			free_args(argc, split);
			exit(write(2, "Error\n", 6));
		}
		i++;
	}
	return (split);
}

int	is_not_integer(char *argv)
{
	if (*argv != '+' && *argv != '-' && ft_isdigit(*argv) == 0)
		return (1);
	if ((*argv == '+' || *argv == '-') && ft_isdigit(*(argv + 1)) == 0)
		return (1);
	while (*++argv)
	{
		if (ft_isdigit(*argv) == 0)
			return (1);
	}
	return (0);
}

int	out_of_limit(char *argv)
{
	long long	n;

	if (!argv || ft_strlen(argv) == 0 || ft_strlen(argv) > 11)
		return (1);
	n = ft_atoi(argv);
	if (n > INT_MAX || n < INT_MIN)
		return (1);
	return (0);
}

int	is_duplicated(t_stack_list *stack)
{
	t_stack_node	*current1;
	t_stack_node	*current2;
	int				dup;

	dup = 0;
	current1 = stack->head;
	while (current1)
	{
		current2 = stack->head;
		while (current2)
		{
			if (current1->value == current2->value)
				dup++;
			current2 = current2->next;
		}
		if (dup > 1)
			return (1);
		dup = 0;
		current1 = current1->next;
	}
	return (0);
}
