/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:45:27 by stopp             #+#    #+#             */
/*   Updated: 2024/01/15 14:58:12 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*biggest;

	biggest = find_max(*stack);
	if (biggest == *stack)
		rotate_a(stack, true);
	else if ((*stack)->next == biggest)
		rr_a(stack, true);
	if ((*stack)->content > (*stack)->next->content)
		swap_a(stack, true);
	return ;
}

static void	finish_stack(t_stack **a)
{
	t_stack	*min;

	min = find_min(*a);
	updt_i(a);
	while ((*a)->content != min->content)
	{
		if (min->above_median)
			rr_a(a, true);
		else
			rotate_a(a, true);
	}
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(a);
	if (len-- > 3 && !sorted(*a))
		push_atob(a, b, true);
	if (len-- > 3 && !sorted(*a))
		push_atob(a, b, true);
	while (len-- > 3 && !sorted(*a))
	{
		updt_stack_a(a, b);
		move_atob(a, b);
	}
	sort_three(a);
	while (*b)
	{
		updt_stack_b(a, b);
		move_btoa(a, b);
	}
	finish_stack(a);
}

t_stack	*find_cheapest(t_stack *a)
{
	while (!(a->cheapest))
		a = a->next;
	return (a);
}
