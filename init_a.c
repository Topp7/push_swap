/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:20:57 by stopp             #+#    #+#             */
/*   Updated: 2024/01/16 17:42:27 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		result = (result * 10) + (*s - '0');
		s++;
	}
	result *= sign;
	return (result);
}

static void	add_new(t_stack **stack, int n)
{
	t_stack	*curr;
	t_stack	*last;

	if (!stack)
		return ;
	curr = malloc (sizeof(t_stack));
	if (!curr)
		return ;
	curr->next = NULL;
	curr->content = n;
	if (!(*stack))
	{
		*stack = curr;
		curr->prev = NULL;
	}
	else
	{
		last = find_last(*stack);
		last->next = curr;
		curr->prev = last;
	}
}

void	make_a(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	n = 0;
	while (argv[i])
	{
		if (syntax(argv[i]) == 1)
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (duplicate(a, (int)n))
			free_errors(a);
		add_new(a, (int)n);
		i++;
	}
}

t_stack	*find_last(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
}
