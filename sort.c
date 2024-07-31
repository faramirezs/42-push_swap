/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:55:42 by alramire          #+#    #+#             */
/*   Updated: 2024/07/31 13:05:14 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort(t_stack_list *stack_a, t_stack_list *stack_b)
{
	if(!stack_b)
		write(1, "Empty stack_b", 13);
	if (is_sorted(stack_a) == 1)
		return;
	else
	{
		if(stack_a->lenght == 2)
		{
			swap(stack_a);
			write(1, "sa\n", 3);
		}
		else if (stack_a->lenght == 3)
		{
			sort_sm(stack_a);
		}
/* 		else
			sort_l(stack_a); */

	}
}
void sort_sm(t_stack_list *stack)
{
	if (stack->head->next->index < stack->head->index && stack->head->index < stack->tail->index)
	{
		swap(stack);
		write(1, "sa\n", 3);
	}
	else if (stack->tail->index < stack->head->index && stack->head->index < stack->head->next->index)
	{
		reverse_rotate(stack);
		write(1, "rra\n", 4);
	}
	else
	{
		swap(stack);
		write(1, "sa\n", 3);
		reverse_rotate(stack);
		write(1, "rra\n", 4);
	}
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
/* void sort_l(t_stack_list *stack_a, t_stack_list	*stack_b)
{

} */
void fill_sort_stack_b (t_stack_list *stack_a, t_stack_list *stack_b)
{
	while(stack_a->lenght > 3)
	{
		if(stack_a->head->index > stack_a->tail->index && stack_a->head->index > stack_a->lenght / 2)
		{
			if(stack_b->lenght >= 2)
			{
				if(stack_b->head->index < stack_b->tail->index)
				{
					rotate(stack_b);
					write(1, "rb\n", 3);
					push(stack_a, stack_b);
					write(1, "pb\n", 3);
				}
				else
				{
					push(stack_a, stack_b);
					write(1, "pb\n", 3);
				}
			}
			else
			{
				push(stack_a, stack_b);
				write(1, "pb\n", 3);
			}
		}
		else if(stack_a->head->index < stack_a->tail->index && stack_a->tail->index > stack_a->lenght / 2)
		{
			if(stack_b->lenght >= 2)
			{
				if(stack_b->head->index < stack_b->tail->index)
					{
						rotate(stack_b);
						write(1, "rb\n", 3);
						reverse_rotate(stack_a);
						write(1, "rra\n", 4);
						push(stack_a, stack_b);
						write(1, "pb\n", 3);
					}
				else
				{
					reverse_rotate(stack_a);
					write(1, "rra\n", 4);
					push(stack_a, stack_b);
					write(1, "pb\n", 3);
				}
			}
			else
			{
				reverse_rotate(stack_a);
				write(1, "rra\n", 4);
				push(stack_a, stack_b);
				write(1, "pb\n", 3);
			}
		}
		else
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
		}
	}
}
