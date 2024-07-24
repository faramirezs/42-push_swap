/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:02:09 by alramire          #+#    #+#             */
/*   Updated: 2024/07/24 13:56:35 by alramire         ###   ########.fr       */
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




//movements

//algorithm

//cost
#endif
