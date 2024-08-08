/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:59:32 by alramire          #+#    #+#             */
/*   Updated: 2024/08/08 10:36:22 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_list *stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	second = stack->head;
	first = stack->head->next;
	second->next = first->next;
	second->prev = first;
	first->next = second;
	first->prev = NULL;
	if (second->next != NULL)
		second->next->prev = second;
	stack->head = first;
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

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	tmp = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	tmp->next = stack->head;
	tmp->prev = NULL;
	stack->head->prev = tmp;
	stack->head = tmp;
}

void	push(t_stack_list *src_stack, t_stack_list *dest_stack)
{
	t_stack_node	*src_second;

	if (src_stack->head == NULL)
		return ;
	src_second = src_stack->head->next;
	if (src_second)
		src_second->prev = NULL;
	else
		src_stack->tail = NULL;
	src_stack->head->next = dest_stack->head;
	if (dest_stack->head)
		dest_stack->head->prev = src_stack->head;
	dest_stack->head = src_stack->head;
	if (!dest_stack->tail)
		dest_stack->tail = dest_stack->head;
	src_stack->head = src_second;
	src_stack->lenght--;
	dest_stack->lenght++;
}
