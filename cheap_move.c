/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheap_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroramirez <alejandroramirez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 21:08:31 by alejandrora       #+#    #+#             */
/*   Updated: 2024/08/04 21:21:59 by alejandrora      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_cheapest_move(t_stack_list *stack_a, t_stack_list *stack_b)
{
	t_stack_node	*cur_b;
	int				cheapest_cost;
	int				cheapest_a;
	int				cheapest_b;
	int				cur_cost;

	cur_b = stack_b->head;
	cheapest_cost = INT_MAX;
	cur_cost = 0;
	while (cur_b)
	{
		cur_cost = get_cheaper_cost(cur_b->cost_a, cur_b->cost_b);
		if (ft_abs(cur_cost) < cheapest_cost)
		{
			cheapest_cost = ft_abs(cur_cost);
			cheapest_a = cur_b->cost_a;
			cheapest_b = cur_b->cost_b;
		}
		cur_b = cur_b->next;
	}
	do_move(stack_a, stack_b, cheapest_a, cheapest_b);
}

int	get_cheaper_cost(int cost_a, int cost_b)
{
	int	result;

	if (cost_a > 0 && cost_b > 0)
	{
		if (cost_a > cost_b)
			result = cost_a;
		else
			result = cost_b;
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		if (cost_a < cost_b)
			result = cost_a;
		else
			result = cost_b;
	}
	else
		result = ft_abs(cost_a) + ft_abs(cost_b);
	return (result);
}

void	do_move(t_stack_list *stack_a, t_stack_list *stack_b, int cheapest_a,
		int cheapest_b)
{
	cost_is_positive(stack_a, stack_b, &cheapest_a, &cheapest_b);
	cost_is_negative(stack_a, stack_b, &cheapest_a, &cheapest_b);
	cost_a_is_positive(stack_a, stack_b, &cheapest_a, &cheapest_b);
	cost_b_is_positive(stack_a, stack_b, &cheapest_a, &cheapest_b);
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
