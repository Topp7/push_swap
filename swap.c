/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:03:59 by stopp             #+#    #+#             */
/*   Updated: 2024/01/15 14:47:38 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **top)
{
	if (!*top || !(*top)->next)
		return ;
	*top = (*top)->next;
	(*top)->prev->prev = *top;
	(*top)->prev->next = (*top)->next;
	if ((*top)->next)
		(*top)->next->prev = (*top)->prev;
	(*top)->next = (*top)->prev;
	(*top)->prev = NULL;
}

void	swap_a(t_stack **stack_a, bool print)
{
	swap(stack_a);
	if (print)
		ft_printf("sa\n");
	return ;
}

void	swap_b(t_stack **stack_b, bool print)
{
	swap(stack_b);
	if (print)
		ft_printf("sb\n");
	return ;
}

void	swap_both(t_stack **stack_a, t_stack **stack_b, bool print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		ft_printf("ss\n");
	return ;
}
