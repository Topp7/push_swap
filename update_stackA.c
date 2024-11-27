/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stackA.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:01:42 by stopp             #+#    #+#             */
/*   Updated: 2024/01/15 14:15:10 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	updt_i(t_stack **stack)
{
	int		index;
	int		median;
	t_stack	*temp;

	index = 0;
	median = stack_len(stack) / 2;
	temp = *stack;
	while (temp)
	{
		temp->i = index++;
		if (temp->i < median)
			temp->above_median = false;
		else
			temp->above_median = true;
		temp = temp->next;
	}
}

static void	updt_target_a(t_stack *a, t_stack *b)
{
	t_stack	*curr_b;
	t_stack	*target_node;
	long	best_match;

	while (a)
	{
		curr_b = b;
		best_match = LONG_MIN;
		while (curr_b)
		{
			if (curr_b->content < a->content
				&& curr_b->content > best_match)
			{
				best_match = curr_b->content;
				target_node = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (best_match == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

void	updt_cost(t_stack *a, t_stack *b)
{
	int	alen;
	int	blen;

	alen = stack_len(&a);
	blen = stack_len(&b);
	while (a)
	{
		a->cost = a->i;
		if (a->above_median)
			a->cost = alen - (a->i);
		if (a->target->above_median)
			a->cost += blen - a->target->i;
		else
			a->cost += a->target->i;
		a = a->next;
	}
}

void	updt_cheapest(t_stack *stack)
{
	long	value;
	t_stack	*node;

	if (!stack)
		return ;
	value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < value)
		{
			value = stack->cost;
			node = stack;
		}
		stack = stack->next;
	}
	node->cheapest = true;
}

void	updt_stack_a(t_stack **a, t_stack **b)
{
	updt_i(a);
	updt_i(b);
	updt_target_a(*a, *b);
	updt_cost(*a, *b);
	updt_cheapest(*a);
}
