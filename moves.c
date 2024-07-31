/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:59:32 by alramire          #+#    #+#             */
/*   Updated: 2024/07/31 10:45:49 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack_list *stack)
{
	if (stack->head && stack->head->next)
	{
		t_stack_node *first;
		t_stack_node *second;

		second = stack->head;
		first = stack->head->next;
		first->prev = NULL;
		second->next = first->next;
		first->next = second;
		if(second->next)
			second->next->prev = second;
		stack->head = first;
	}
	else
		return;
}

void rotate (t_stack_list *stack)
{
	if (stack->head && stack->head->next)
	{
		t_stack_node * tmp;

		tmp = stack->head;
		stack->head = stack->head->next;
		tmp->prev = stack->tail;
		stack->head->next->prev = NULL;
		tmp->next = NULL;
		stack->tail->next = tmp;
		stack->tail = tmp;
	}
	else
		return;

}

void reverse_rotate (t_stack_list *stack)
{
	if (stack->tail && stack->tail->prev)
	{
		t_stack_node * tmp;

		tmp = stack->tail;
		stack->tail = stack->tail->prev;
		stack->tail->next = NULL;
		tmp->next = stack->head;
		tmp->prev = NULL;
		stack->head->prev = tmp;
		stack->head = tmp;
	}
	else
		return;

}

void push(t_stack_list *src, t_stack_list *dest)
{
	if (src->head)
	{
		t_stack_node *tmp_src;

		tmp_src = src->head->next;
		if (tmp_src)
			tmp_src->prev = NULL;
		else
			src->tail = NULL;
		src->head->next = dest->head;
		if (dest->head)
			dest->head->prev = src->head;
		dest->head = src->head;
		if (!dest->tail)
			dest->tail = src->head;
		src->head = tmp_src;
		src->lenght--;
		dest->lenght++;
	}
	else
		return;
}
