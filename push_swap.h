/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:08:11 by stopp             #+#    #+#             */
/*   Updated: 2024/01/12 14:58:25 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	int				i;
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*find_last(t_stack *stack);
bool	sorted(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
int		stack_len(t_stack **stack);
t_stack	*find_cheapest(t_stack *a);

void	free_stack(t_stack **stack);
void	free_errors(t_stack **a);
int		syntax(char *str);
int		duplicate(t_stack **stack, int n);
void	make_a(t_stack **a, char **argv);

void	sort_three(t_stack **stack);
void	sort_stacks(t_stack **a, t_stack **b);

void	updt_i(t_stack **stack);
void	updt_cheapest(t_stack *stack);
void	updt_stack_a(t_stack **a, t_stack **b);
void	updt_cost(t_stack *a, t_stack *b);

void	updt_stack_b(t_stack **a, t_stack **b);
void	move_atob(t_stack **a, t_stack **b);
void	move_btoa(t_stack **a, t_stack **b);

void	rotate_a(t_stack **a, bool print);
void	rotate_b(t_stack **b, bool print);
void	rotate_both(t_stack **a, t_stack **b, bool print);

void	rr_a(t_stack **a, bool print);
void	rr_b(t_stack **b, bool print);
void	rr_both(t_stack **a, t_stack **b, bool print);

void	push_atob(t_stack **a, t_stack **b, bool print);
void	push_btoa(t_stack **a, t_stack **b, bool print);

void	swap_a(t_stack **stack_a, bool print);
void	swap_b(t_stack **stack_b, bool print);
void	swap_both(t_stack **stack_a, t_stack **stack_b, bool print);

#endif
