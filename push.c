/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:15:01 by stopp             #+#    #+#             */
/*   Updated: 2023/12/18 17:42:03 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = push_node->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	push_node->next = *dst;
	if (*dst)
		(*dst)->prev = push_node;
	*dst = push_node;
}

void	push_atob(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (print)
		ft_printf("pb\n");
	return ;
}

void	push_btoa(t_stack **a, t_stack **b, bool print)
{
	push(b, a);
	if (print)
		ft_printf("pa\n");
	return ;
}
