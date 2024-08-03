/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroramirez <alejandroramirez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:48:11 by alramire          #+#    #+#             */
/*   Updated: 2024/08/03 22:08:01 by alejandrora      ###   ########.fr       */
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
	print_stack_value(stack_a);
	fill_index(stack_a);
	stack_b = new_stack(0, NULL);
	fill_current_position(stack_a);
	print_stack_value(stack_a);
	sort(stack_a, stack_b);
	print_stack_value(stack_b);
	print_stack_value(stack_a);
	fill_positions(stack_a, stack_b);


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



