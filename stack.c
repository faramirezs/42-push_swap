/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:59:21 by alramire          #+#    #+#             */
/*   Updated: 2024/07/24 16:32:42 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fill_stack (t_stack_list *stack, char **argv, int i)
{
	while(argv[i])
	{
		add_node(stack, ft_atoi(argv[i]));
		i++;
	}
}

t_stack_list *new_stack (int argc, char **argv)
{
	t_stack_list *stack;

	stack = (t_stack_list*)malloc(sizeof(t_stack_list));
	if(!stack)
		exit(write(2, "Error creating new stack\n", 26));
	ft_memset(stack, 0, sizeof(t_stack_list));
	if (argc == 2)
		fill_stack(stack, argv, 0);
	else
		exit(write(2, "More than 2 arguments\n", 23));
	return(stack);
}

void add_node (t_stack_list *stack, int value)
{
	t_stack_node *new_node;

	new_node = (t_stack_node*)malloc(sizeof(t_stack_node));
	if(!new_node)
	{
		clear_stack(stack);
		exit(write(2, "Error creating new node\n", 23));
	}
	ft_memset(new_node, 0, sizeof(t_stack_node));
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = stack->tail;
	if(!stack->head)
		stack->head = new_node;
	if(stack->tail)
		stack->tail->next = new_node;
	stack->tail = new_node;
	stack->lenght++;
}

void clear_stack (t_stack_list *stack)
{
	t_stack_node * current;

	if (stack)
	{
		while (stack->head)
		{
			current = stack->head->next;
			free(stack->head);
			stack->head = current;
		}
		free(stack);
	}
}
