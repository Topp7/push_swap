/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:08:07 by stopp             #+#    #+#             */
/*   Updated: 2024/01/16 18:02:36 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	single_argument(t_stack **a, char **argv)
{
	int		i;

	argv = ft_split(argv[1], ' ');
	make_a(a, argv);
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		single_argument(&a, argv);
	else
		make_a(&a, argv + 1);
	if (!sorted(a))
	{
		if (stack_len(&a) == 2)
			swap_a(&a, true);
		else if (stack_len(&a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
