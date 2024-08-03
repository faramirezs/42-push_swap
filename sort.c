/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroramirez <alejandroramirez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:55:42 by alramire          #+#    #+#             */
/*   Updated: 2024/08/03 13:05:30 by alejandrora      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort(t_stack_list *stack_a, t_stack_list *stack_b)
{
	if (is_sorted(stack_a) == 1)
	{
		write(1, "ok\n", 3);
		return;
	}
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
		else
		{
			fill_sort_stack_b(stack_a, stack_b);
			sort_sm(stack_a);
		}
	}
}
void sort_sm(t_stack_list *stack)
{
	if (stack->head->next->index < stack->head->index && stack->head->index < stack->tail->index)
	{
		#213

		swap(stack);
		write(1, "sa\n", 3);
	}
	else if (stack->tail->index < stack->head->index && stack->head->index < stack->head->next->index)
	{
		#231

		reverse_rotate(stack);
		write(1, "rra\n", 4);
	}
	else if (stack->tail->index < stack->head->index && stack->tail->index > stack->head->next->index)
	{
		#312

		rotate(stack);
		write(1, "ra\n", 4);
	}
	else if (stack->tail->index > stack->head->index && stack->head->index < stack->head->next->index)
	{
		#132

		swap(stack);
		write(1, "sa\n", 3);
		rotate(stack);
		write(1, "ra\n", 4);
	}
	else if (stack->tail->index < stack->head->index && stack->tail->index < stack->head->next->index)
	{
		#321321

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
			max_top_stack_b(stack_b);
			push(stack_a, stack_b);
			write(1, "pb\n", 4);
			//max_top_stack_b(stack_b);
		}
		else if(stack_a->head->index < stack_a->tail->index && stack_a->tail->index > stack_a->lenght / 2)
		{
			max_top_stack_b(stack_b);
			reverse_rotate(stack_a);
			write(1, "rra\n", 4);
			push(stack_a, stack_b);
			write(1, "pb\n", 3);
			//max_top_stack_b(stack_b);
		}
		else
		{
			max_top_stack_b(stack_b);
			rotate(stack_a);
			write(1, "ra\n", 3);
			//max_top_stack_b(stack_b);
		}
	}
}

void max_top_stack_b(t_stack_list *stack_b)
{
	if(stack_b && stack_b->lenght >= 2 && stack_b->head->index < stack_b->tail->index)
	{
		rotate(stack_b);
		write(1, "rb\n", 3);
	}

}



/* void fill_sort_stack_b (t_stack_list *stack_a, t_stack_list *stack_b)
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
} */
