/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:02:09 by alramire          #+#    #+#             */
/*   Updated: 2024/07/31 12:02:55 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

//stack
void fill_stack (t_stack_list *stack, char **argv, int i);
t_stack_list *new_stack (int argc, char **argv);
void new_node (t_stack_list *stack, int value);
void clear_stack (t_stack_list *stack);
void clear_stack (t_stack_list *stack);
int print_stack_value(t_stack_list *stack);
int print_stack_curr_pos(t_stack_list *stack);
int print_stack_targ_pos(t_stack_list *stack);
int print_stack_index(t_stack_list *stack);

//inputs
char **norm_input(int argc, char **argv);
char **norm_two_args(int argc, char **argv);
int is_not_integer(char *argv);
int out_of_limit(char *argv);
void free_args(int argc, char **argv);

//movements
void swap(t_stack_list *stack);
void rotate (t_stack_list *stack);
void reverse_rotate (t_stack_list *stack);
void push(t_stack_list *src, t_stack_list *dest);

//algorithm

//positions
void fill_current_position (t_stack_list *stack);
int get_index (t_stack_list *stack, int value);
int	get_target_pos(t_stack_list *stack, int index_b, int target_index, int target_pos);
void fill_positions(t_stack_list *stack_a, t_stack_list *stack_b);

//cost

//sorting
void sort(t_stack_list *stack_a, t_stack_list *stack_b);
void sort_sm(t_stack_list *stack);
int is_sorted(t_stack_list *stack);
//void sort_l(t_stack_list *stack);
void fill_sort_stack_b (t_stack_list *stack_a, t_stack_list *stack_b);


//index
void fill_index (t_stack_list *stack);
t_stack_node *find_highest_value_no_index(t_stack_list *stack);
#endif
