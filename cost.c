/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroramirez <alejandroramirez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:25:02 by alejandrora       #+#    #+#             */
/*   Updated: 2024/08/03 22:08:02 by alejandrora      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void get_cost_b (t_stack_list *stack_b)
{
	t_stack_node *current;

	current = stack_b->head;
	while(current)
	{
		if(current->current_pos >= stack_b->lenght / 2)
			current->cost_b = current->current_pos;
		else
			current->cost_b = stack_b->lenght - current->current_pos + 2
	}
}

