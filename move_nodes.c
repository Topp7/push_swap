/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:59:48 by stopp             #+#    #+#             */
/*   Updated: 2024/01/13 20:19:59 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_setup(t_stack **stack, t_stack *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_median)
				rr_a(stack, true);
			else
				rotate_a(stack, true);
		}
		else if (name == 'b')
		{
			if (top_node->above_median)
				rr_b(stack, true);
			else
				rotate_b(stack, true);
		}
	}
}

void	move_atob(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*a);
	if (!(cheapest->above_median) && !(cheapest->target->above_median))
	{
		while (*b != cheapest->target && *a != cheapest)
			rotate_both(a, b, true);
		updt_i(a);
		updt_i(b);
	}
	else if (cheapest->above_median && cheapest->target->above_median)
	{
		while (*b != cheapest->target && *a != cheapest)
			rr_both(a, b, true);
		updt_i(a);
		updt_i(b);
	}
	push_setup(a, cheapest, 'a');
	push_setup(b, cheapest->target, 'b');
	push_atob(a, b, true);
}

void	move_btoa(t_stack **a, t_stack **b)
{
	push_setup(a, (*b)->target, 'a');
	push_btoa(a, b, true);
}
