/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:40:40 by alramire          #+#    #+#             */
/*   Updated: 2024/08/08 09:13:37 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adjust_stack(t_stack_list *stack_a)
{
	int	lowest_pos;
	int	len;

	len = stack_a->lenght;
	lowest_pos = lowest_index(stack_a);
	if (lowest_pos > len / 2)
	{
		while (lowest_pos < len)
		{
			reverse_rotate(stack_a);
			write(1, "rra\n", 4);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
			lowest_pos--;
		}
	}
}

void	max_top_stack_b(t_stack_list *stack_b)
{
	if (stack_b && stack_b->lenght >= 2
		&& stack_b->head->index < stack_b->tail->index)
	{
		rotate(stack_b);
		write(1, "rb\n", 3);
	}
}
