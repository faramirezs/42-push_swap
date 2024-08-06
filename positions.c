/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:09:51 by alramire          #+#    #+#             */
/*   Updated: 2024/08/06 13:53:46 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_positions(t_stack_list *stack_a, t_stack_list *stack_b)
{
	t_stack_node	*current;
	int				target_pos;

	current = stack_b->head;
	fill_current_position(stack_a);
	fill_current_position(stack_b);
	target_pos = 0;
	while (current)
	{
		target_pos = get_target_pos(stack_a, current->index);
		current->target_pos = target_pos;
		current = current->next;
	}
}

int	lowest_index(t_stack_list *stack)
{
	t_stack_node	*current;
	int				low_index;
	int				low_pos;

	current = stack->head;
	low_index = INT_MAX;
	fill_current_position(stack);
	low_pos = current->current_pos;
	while (current)
	{
		if (current->index < low_index)
		{
			low_index = current->index;
			low_pos = current->current_pos;
		}
		current = current->next;
	}
	return (low_pos);
}

void	fill_current_position(t_stack_list *stack)
{
	t_stack_node	*current;
	int				i;

	current = stack->head;
	i = 0;
	while (current)
	{
		current->current_pos = i;
		current = current->next;
		i++;
	}
}
