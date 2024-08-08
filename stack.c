/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:59:21 by alramire          #+#    #+#             */
/*   Updated: 2024/08/08 15:08:09 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack_list *stack, int argc, char **argv, int i)
{
	while (argv[i])
	{
		new_node(stack, ft_atoi(argv[i]));
		i++;
	}
	if (is_duplicated(stack))
	{
		clear_stack(stack);
		free_args(argc, argv);
		exit(write(2, "Error\n", 6));
	}
}

t_stack_list	*new_stack(int argc, char **argv)
{
	t_stack_list	*stack;

	stack = (t_stack_list *)malloc(sizeof(t_stack_list));
	if (!stack)
	{
		clear_stack(stack);
		free_args(argc, argv);
		exit(write(2, "Error\n", 6));
	}
	ft_memset(stack, 0, sizeof(t_stack_list));
	if (argc == 2)
		fill_stack(stack, argc, argv, 0);
	else if (argc > 2)
		fill_stack(stack, argc, argv, 1);
	return (stack);
}

void	new_node(t_stack_list *stack, int value)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
	{
		clear_stack(stack);
		exit(write(2, "Error\n", 6));
	}
	ft_memset(new_node, 0, sizeof(t_stack_node));
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = stack->tail;
	if (!stack->head)
		stack->head = new_node;
	if (stack->tail)
		stack->tail->next = new_node;
	stack->tail = new_node;
	stack->lenght++;
}

void	clear_stack(t_stack_list *stack)
{
	t_stack_node	*current;

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
