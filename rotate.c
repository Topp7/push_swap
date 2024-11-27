/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:26:41 by stopp             #+#    #+#             */
/*   Updated: 2024/01/13 19:09:11 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	(*stack)->next->prev = NULL;
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
	last->next->prev = last;
	return ;
}

void	rotate_a(t_stack **a, bool print)
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
	return ;
}

void	rotate_b(t_stack **b, bool print)
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
	return ;
}

void	rotate_both(t_stack **a, t_stack **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
	return ;
}
