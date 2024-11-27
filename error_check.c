/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:37:40 by stopp             #+#    #+#             */
/*   Updated: 2024/01/16 18:06:35 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax(char *str)
{
	int	i;

	if (!(*str == '+' || *str == '-') && !(str[0] >= '0' && str[0] <= '9'))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	i = 1;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	duplicate(t_stack **stack, int n)
{
	t_stack	*temp;

	if (!(*stack))
		return (0);
	temp = *stack;
	while (temp)
	{
		if (temp->content == n)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free (current);
		current = temp;
	}
	*stack = NULL;
}

void	free_errors(t_stack **a)
{
	free_stack(a);
	write (1, "Error\n", 6);
	exit(1);
}
