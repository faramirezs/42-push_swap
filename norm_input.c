/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:26:02 by alramire          #+#    #+#             */
/*   Updated: 2024/07/24 17:38:02 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **norm_input(int argc, char **argv)
{
	int i;

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
}
