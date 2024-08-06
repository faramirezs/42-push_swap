/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:50:18 by alramire          #+#    #+#             */
/*   Updated: 2024/08/06 14:44:15 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_index(t_stack_list *stack)
{
	t_stack_node	*current;
	int				len;

	len = stack->lenght;
	current = NULL;
	while (len > 0)
	{
		current = find_highest_value_no_index(stack);
		if (current)
		{
			current->index = len;
			len--;
		}
		else
			break ;
	}
}

t_stack_node	*find_highest_value_no_index(t_stack_list *stack)
{
	t_stack_node	*current;
	t_stack_node	*highest;
	int				h_value;

	current = stack->head;
	highest = NULL;
	h_value = INT_MIN;
	while (current)
	{
		if (!highest)
			highest = current;
		if (!current->index && h_value < current->value)
		{
			h_value = current->value;
			highest = current;
		}
		current = current->next;
	}
	return (highest);
}
