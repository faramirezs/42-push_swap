/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroramirez <alejandroramirez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:09:51 by alramire          #+#    #+#             */
/*   Updated: 2024/08/04 21:35:14 by alejandrora      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_positions(t_stack_list *stack_a, t_stack_list *stack_b)
{
	t_stack_node	*cur_b;
	int				target_pos;

	cur_b = stack_b->head;
	fill_current_position(stack_a);
	fill_current_position(stack_b);
	target_pos = 0;
	while (cur_b)
	{
		target_pos = get_target_pos(stack_a, cur_b->index, INT_MAX, target_pos);
		cur_b->target_pos = target_pos;
		cur_b = cur_b->next;
	}
}



/* int get_target_pos(t_stack_list *stack_a, int index_b)
{
	t_stack_node *current;
	int target_pos;
	int target_index;

	current = stack_a->head;
	target_pos = -1;
	target_index = INT_MAX;
	while(current)
	{
		if(current->index > index_b && current->index < target_index)
		{
			target_index = current->index;
			target_pos = current->current_pos;
		}
		current = current->next;
	}
	if (target_index != INT_MAX)
		return(target_pos);
	current = stack_a->head;
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
} */

int lowest_index (t_stack_list *stack)
{
	t_stack_node *current;

	int low_index;
	int low_pos;

	current = stack->head;

	low_index = INT_MAX;
	fill_current_position(stack);
	low_pos = current->current_pos;
	while(current)
	{
		if(current->index < low_index)
		{
			low_index = current->index;
			low_pos = current->current_pos;
		}
		current = current->next;
	}
	return(low_pos);
}

/* void fill_positions(t_stack_list *stack_a, t_stack_list *stack_b)
{
	t_stack_node	*cur_b;
	int				target_pos;

	cur_b = stack_b->head;
	fill_current_position(stack_a);
	fill_current_position(stack_b);
	printf("fill current inside fill positions done\n");
	target_pos = 0;
	while (cur_b)
	{
		target_pos = get_target_pos(stack_a, cur_b->value);
		cur_b->target_pos = target_pos;
		cur_b = cur_b->next;
	}
} */


void fill_current_position (t_stack_list *stack)
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

int	get_target_pos(t_stack_list *stack, int index_b, int target_index,
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
}

/* int get_target_pos(t_stack_list *stack_a, int b_value)
{
	t_stack_node *current;
	int diff;
	int counter;
	int target_pos;

	current = stack_a->head;
	counter = INT_MAX;
	target_pos = -1;

	while(current)
	{
		diff = current->value - b_value;
		printf("diff= %i\n",diff);
		if((diff < counter) && ((current->value > b_value)))
		{
			counter = diff;
			target_pos = current->value;
		}
		current = current->next;
	}
	//current = stack_a->head;
	if (target_pos == -1)
		return (-1);
	return (get_index(stack_a, target_pos));
} */

int get_index (t_stack_list *stack, int value)
{
	t_stack_node *current;

	current = stack->head;
	while(current)
	{
		if(current->value == value)
			return(current->index);
		current = current->next;
	}
	return(-1);
}
