/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:48:11 by alramire          #+#    #+#             */
/*   Updated: 2024/07/26 09:45:28 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv) {
	t_stack_list *stack_a;
	t_stack_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;

	argv = norm_input(argc, argv);
	stack_a = new_stack(argc, argv);
	print_stack(stack_a);
	swap(stack_a);
	print_stack(stack_a);



/* 	if (argc == 2)
	{
		printf("argc == 2\n");
		get_int(argv[1], stack_a);
		printf("after get_int\n");
		swap(stack_a);
		print_stack(&stack_a);
	}
	else */
	return (0);
}



