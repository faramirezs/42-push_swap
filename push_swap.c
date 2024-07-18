/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:48:11 by alramire          #+#    #+#             */
/*   Updated: 2024/07/18 13:44:46 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

typedef struct s_stack_node
{
	int					value;
	int					current_pos;
	int					target_pos;
	int					index;
	int					cost_a;
	int					cost_b;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_stack_list
{
	t_stack_node	*head;
	t_stack_node	*tail;
	int				lenght;

}	t_stack_list;

void fill(t_stack_list *stack_a, int value)
{
	t_stack_node *new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	new_node->value = value;
/* 	new_node->current_pos = 0;
	new_node->target_pos = 0;
	new_node->index = 0;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->next = NULL;
	new_node->prev = NULL; */

	if (stack_a->head == NULL)
	{
		stack_a->head = new_node;
		stack_a->tail = new_node;
	}
	else
	{
		new_node->prev = stack_a->head;
		stack_a->head->next = new_node;
		stack_a->tail = new_node;
	}
	stack_a->lenght++;
	printf("The list has %i nodes\n", stack_a->lenght);
}

int get_int(char *str, t_stack_list *stack){
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == 0 || str[i] == 32)
			i++;
		else if (str[i] >= 48 && str[i] <= 57)
		{
			printf("integer = %i\n", atoi(&str[i]));
			fill(stack, atoi(&str[i]));
			i++;
		}
	}
	printf("Head %i\n", stack->head->value);
	printf("Tail %i\n", stack->tail->value);
	return (0);
}

int main (int argc, char **argv) {
	t_stack_list stack_a = {NULL, NULL, 0};

	if (argc == 2)
	{
		printf("argc == 2\n");
		get_int(argv[1], &stack_a);
	}

	else
		return (0);
}
