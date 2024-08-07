/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:50:05 by alramire          #+#    #+#             */
/*   Updated: 2024/08/07 17:28:15 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	get_target_pos(t_stack_list *stack, int index_b, int target_index,
		int target_pos)
{
	t_stack_node	*current_a;

	current_a = stack->head;
	while (current_a)
	{
		if (current_a->index > index_b && current_a->index < target_index)
		{
			target_index = current_a->index;
			target_pos = current_a->current_pos;
		}
		current_a = current_a->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	current_a = stack->head;
	while (current_a)
	{
		if (current_a->index < target_index)
		{
			target_index = current_a->index;
			target_pos = current_a->current_pos;
		}
		current_a = current_a->next;
	}
	return (target_pos);
} */

int	find_initial_target_pos(t_stack_list *stack_a, int index_b,
		int *target_index)
{
	t_stack_node	*current;
	int				target_pos;

	current = stack_a->head;
	target_pos = -1;
	*target_index = INT_MAX;
	while (current)
	{
		if (current->index > index_b && current->index < *target_index)
		{
			*target_index = current->index;
			target_pos = current->current_pos;
		}
		current = current->next;
	}
	return (target_pos);
}

int	find_final_target_pos(t_stack_list *stack_a, int target_index)
{
	t_stack_node	*current;
	int				target_pos;

	current = stack_a->head;
	target_pos = -1;
	while (current)
	{
		if (current->index < target_index)
		{
			target_index = current->index;
			target_pos = current->current_pos;
		}
		current = current->next;
	}
	return (target_pos);
}

int	get_target_pos(t_stack_list *stack_a, int index_b)
{
	int	target_index;
	int	target_pos;

	target_pos = find_initial_target_pos(stack_a, index_b, &target_index);
	if (target_index != INT_MAX)
		return (target_pos);
	return (find_final_target_pos(stack_a, target_index));
}
