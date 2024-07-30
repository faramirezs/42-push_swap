/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:55:42 by alramire          #+#    #+#             */
/*   Updated: 2024/07/30 14:48:21 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort(t_stack_list *stack_a, t_stack_list *stack_b)
{
	if (is_sorted(stack_a) == 1)
		return;
	else
	{
		if(stack_a->lenght == 2)
		{
			swap(stack_a);
			write(1, "sa\n", 2);
		}
		else if (stack_a->lenght == 3)
		{
			sort_sm(stack_a);
		}
		else
			sort_l(stack_a);

	}
}
void sort_sm(t_stack_list *stack)
{

}


int is_sorted(t_stack_list *stack)
{
	t_stack_node *current;

	current = stack->head;
	while(current && current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}
