/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:26:02 by alramire          #+#    #+#             */
/*   Updated: 2024/07/25 18:37:25 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **norm_input(int argc, char **argv)
{
	if(argc == 2)
		argv = norm_two_args(argc, argv);
	else
		exit(1);
	return(argv);
}

char **norm_two_args(int argc, char **argv)
{
	int i;
	char **split;

	split = ft_split(argv[1], ' ');
	if (!split || !*split)
		exit(write(2, "Error\n", 6));
	i = 0;
	while (split[i])
	{
		if(is_not_integer(split[i]) || out_of_limit(split[i]))
		{
			free_args(argc, split);
			exit(write(2, "Error\n", 6));
		}
		i++;
	}
	return (split);
}
int is_not_integer(char *argv)
{
	if((*argv != '+' || *argv != '-') && ft_isdigit(*argv) == 0)
		return(1);
	if((*argv == '+' || *argv == '-') && ft_isdigit(*(argv + 1) == 0))
		return(1);
	while(*++argv)
	{
		if(ft_isdigit(*argv) == 0)
			return(1);
	}
	return (0);
}
int out_of_limit(char *argv)
{
	int n;

	n = ft_atoi(argv);
	if (n > INT_MAX || n < INT_MIN)
		return(1);
	return(0);
}

//void is_duplicated() esta funcion tiene los siguientes input param: stack, argv, argc, current note y verifica que el current node no se repita con los otros nodos


void free_args(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
}
