/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:59:21 by alramire          #+#    #+#             */
/*   Updated: 2024/07/30 11:08:37 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fill_stack (t_stack_list *stack, char **argv, int i)
{
	while(argv[i])
	{
		new_node(stack, ft_atoi(argv[i]));
		i++;
	}
}

t_stack_list *new_stack (int argc, char **argv)
{
	t_stack_list *stack;

	stack = (t_stack_list*)malloc(sizeof(t_stack_list));
	if(!stack)
		exit(write(2, "Error\n", 6));
	ft_memset(stack, 0, sizeof(t_stack_list));
	if (argc == 2)
		fill_stack(stack, argv, 0);
	else if (argc > 2)
		fill_stack(stack, argv, 1);
	return(stack);
}

void new_node (t_stack_list *stack, int value)
{
	t_stack_node *new_node;

	new_node = (t_stack_node*)malloc(sizeof(t_stack_node));
	if(!new_node)
	{
		clear_stack(stack);
		exit(write(2, "Error\n", 6));
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

int print_stack_value(t_stack_list *stack)
{
	t_stack_node *current;
	int i;

	i = 1;
	current = stack->head;
	while (current)
	{
		printf("Nodo[%i]: %d| index(%i)\n", i++, current->value, current->index);
		current = current->next;
	}
	printf("Head: %i\n", stack->head->value);
	printf("Tail: %i\n", stack->tail->value);
	printf("\n");
	return (0);
}

int print_stack_curr_pos(t_stack_list *stack)
{
	t_stack_node *current;
	int i;

	i = 1;
	current = stack->head;
	while (current)
	{
		printf("Current pos[%i]: %d\n", i++, current->current_pos);
		current = current->next;
	}
	printf("Head: %i\n", stack->head->current_pos);
	printf("Tail: %i\n", stack->tail->current_pos);
	printf("\n");
	return (0);
}
int print_stack_targ_pos(t_stack_list *stack)
{
	t_stack_node *current;
	int i;

	i = 1;
	current = stack->head;
	while (current)
	{
		printf("Target pos[%i]: %d\n", i++, current->target_pos);
		current = current->next;
	}
	printf("Head: %i\n", stack->head->target_pos);
	printf("Tail: %i\n", stack->tail->target_pos);
	printf("\n");
	return (0);
}
int print_stack_index(t_stack_list *stack)
{
	t_stack_node *current;
	int i;

	i = 1;
	current = stack->head;
	while (current)
	{
		printf("Index[%i]: %d\n", i++, current->index);
		current = current->next;
	}
	printf("Head: %i\n", stack->head->index);
	printf("Tail: %i\n", stack->tail->index);
	printf("\n");
	return (0);
}
