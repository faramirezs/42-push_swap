/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:59:32 by alramire          #+#    #+#             */
/*   Updated: 2024/08/06 13:38:49 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_list *stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (stack->head && stack->head->next)
	{
		second = stack->head;
		first = stack->head->next;
		first->prev = NULL;
		second->next = first->next;
		first->next = second;
		if (second->next)
			second->next->prev = second;
		stack->head = first;
	}
	else
		return ;
}

void	rotate(t_stack_list *stack)
{
	t_stack_node	*tmp;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	tmp->prev = stack->tail;
	tmp->next = NULL;
	stack->tail->next = tmp;
	stack->tail = tmp;
}

void	reverse_rotate(t_stack_list *stack)
{
	t_stack_node	*tmp;

	if (stack->tail && stack->tail->prev)
	{
		tmp = stack->tail;
		stack->tail = stack->tail->prev;
		stack->tail->next = NULL;
		tmp->next = stack->head;
		tmp->prev = NULL;
		stack->head->prev = tmp;
		stack->head = tmp;
	}
	else
		return ;
}

void	push(t_stack_list *src, t_stack_list *dest)
{
	t_stack_node	*tmp_src;

	if (src->head)
	{
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
		return ;
}
