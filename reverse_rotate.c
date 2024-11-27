/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:26:18 by stopp             #+#    #+#             */
/*   Updated: 2024/01/12 18:41:08 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->next = *stack;
	(*stack)->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
	*stack = last;
	return ;
}

void	rr_a(t_stack **a, bool print)
{
	reverse_rotate(a);
	if (print)
		ft_printf("rra\n");
	return ;
}

void	rr_b(t_stack **b, bool print)
{
	reverse_rotate(b);
	if (print)
		ft_printf("rrb\n");
	return ;
}

void	rr_both(t_stack **a, t_stack **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		ft_printf("rrr\n");
	return ;
}
