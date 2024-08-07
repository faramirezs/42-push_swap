/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:55:42 by alramire          #+#    #+#             */
/*   Updated: 2024/08/07 17:11:09 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack_list *stack_a, t_stack_list *stack_b)
{
	if (is_sorted(stack_a) == 1)
	{
		return ;
	}
	else
	{
		if (stack_a->lenght == 2)
		{
			swap(stack_a);
			write(1, "sa\n", 3);
		}
		else if (stack_a->lenght == 3)
		{
			sort_sm(stack_a);
		}
		else
		{
			sort_l(stack_a, stack_b);
		}
	}
}

void	sort_sm(t_stack_list *stack)
{
	if (stack->head->index > stack->head->next->index)
	{
		swap(stack);
		write(1, "sa\n", 3);
	}
	if (stack->head->index > stack->tail->index)
	{
		reverse_rotate(stack);
		write(1, "rra\n", 4);
	}
	if (stack->head->next->index > stack->tail->index)
	{
		reverse_rotate(stack);
		write(1, "rra\n", 4);
		if (stack->head->index > stack->head->next->index)
		{
			swap(stack);
			write(1, "sa\n", 3);
		}
	}
}

int	is_sorted(t_stack_list *stack)
{
	t_stack_node	*current;

	current = stack->head;
	while (current && current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_l(t_stack_list *stack_a, t_stack_list *stack_b)
{
	fill_sort_stack_b(stack_a, stack_b);
	sort_sm(stack_a);
	while (stack_b->lenght > 0)
	{
		fill_positions(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (is_sorted(stack_a) == 0)
		adjust_stack(stack_a);
}

void	fill_sort_stack_b(t_stack_list *stack_a, t_stack_list *stack_b)
{
	while (stack_a->lenght > 3)
	{
		if (stack_a->head->index > stack_a->tail->index
			&& stack_a->head->index > stack_a->lenght / 2)
		{
			max_top_stack_b(stack_b);
			push(stack_a, stack_b);
			write(1, "pb\n", 3);
		}
		else if (stack_a->head->index < stack_a->tail->index
			&& stack_a->tail->index > stack_a->lenght / 2)
		{
			max_top_stack_b(stack_b);
			reverse_rotate(stack_a);
			write(1, "rra\n", 4);
			push(stack_a, stack_b);
			write(1, "pb\n", 3);
		}
		else
		{
			max_top_stack_b(stack_b);
			rotate(stack_a);
			write(1, "ra\n", 3);
		}
	}
}
