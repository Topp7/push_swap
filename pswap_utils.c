/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:33:32 by stopp             #+#    #+#             */
/*   Updated: 2024/01/12 16:13:01 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	stack_len(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	if (!temp)
		return (i);
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_stack	*find_max(t_stack *stack)
{
	long	max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->content > max)
		{
			max_node = stack;
			max = max_node->content;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*find_min(t_stack *stack)
{
	long	min;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->content < min)
		{
			min_node = stack;
			min = min_node->content;
		}
		stack = stack->next;
	}
	return (min_node);
}
