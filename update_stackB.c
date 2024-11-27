/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stackB.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:01:39 by stopp             #+#    #+#             */
/*   Updated: 2024/01/12 17:59:10 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	updt_target_b(t_stack *a, t_stack *b)
{
	t_stack	*curr_a;
	t_stack	*target_node;
	long	best_match;

	while (b)
	{
		curr_a = a;
		best_match = LONG_MAX;
		while (curr_a)
		{
			if (curr_a->content > b->content
				&& curr_a->content < best_match)
			{
				best_match = curr_a->content;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best_match == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	updt_stack_b(t_stack **a, t_stack **b)
{
	updt_i(a);
	updt_i(b);
	updt_target_b(*a, *b);
}
