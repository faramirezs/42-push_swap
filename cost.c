/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:25:02 by alejandrora       #+#    #+#             */
/*   Updated: 2024/08/06 13:39:51 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stack_list *stack_a, t_stack_list *stack_b)
{
	t_stack_node	*current;

	current = stack_b->head;
	while (current)
	{
		current->cost_b = current->current_pos;
		if (current->current_pos > stack_b->lenght / 2)
			current->cost_b = (stack_b->lenght - current->current_pos) * -1;
		current->cost_a = current->target_pos;
		if (current->target_pos > stack_a->lenght / 2)
			current->cost_a = (stack_a->lenght - current->target_pos) * -1;
		current = current->next;
	}
}

void	cost_is_positive(t_stack_list *stack_a, t_stack_list *stack_b,
		int *cheapest_a, int *cheapest_b)
{
	if (*cheapest_a > 0 && *cheapest_b > 0)
	{
		while (*cheapest_a > 0 && *cheapest_b > 0)
		{
			rotate(stack_a);
			rotate(stack_b);
			write(1, "rr\n", 3);
			(*cheapest_a)--;
			(*cheapest_b)--;
		}
	}
}

void	cost_is_negative(t_stack_list *stack_a, t_stack_list *stack_b,
		int *cheapest_a, int *cheapest_b)
{
	if (*cheapest_a < 0 && *cheapest_b < 0)
	{
		while (*cheapest_a < 0 && *cheapest_b < 0)
		{
			reverse_rotate(stack_a);
			reverse_rotate(stack_b);
			write(1, "rrr\n", 4);
			(*cheapest_a)++;
			(*cheapest_b)++;
		}
	}
}

void	cost_a_is_positive(t_stack_list *stack_a, t_stack_list *stack_b,
		int *cheapest_a, int *cheapest_b)
{
	if (*cheapest_a >= 0 && *cheapest_b <= 0)
	{
		while (*cheapest_a > 0)
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
			(*cheapest_a)--;
		}
		while (*cheapest_b < 0)
		{
			reverse_rotate(stack_b);
			write(1, "rrb\n", 4);
			(*cheapest_b)++;
		}
	}
}

void	cost_b_is_positive(t_stack_list *stack_a, t_stack_list *stack_b,
		int *cheapest_a, int *cheapest_b)
{
	if (*cheapest_a <= 0 && *cheapest_b >= 0)
	{
		while (*cheapest_a < 0)
		{
			reverse_rotate(stack_a);
			write(1, "rra\n", 4);
			(*cheapest_a)++;
		}
		while (*cheapest_b > 0)
		{
			rotate(stack_b);
			write(1, "rb\n", 3);
			(*cheapest_b)--;
		}
	}
}
