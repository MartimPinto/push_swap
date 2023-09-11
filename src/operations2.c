/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:40:49 by mcarneir          #+#    #+#             */
/*   Updated: 2023/09/11 13:25:34 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_rrr(t_stack **stack_a, t_stack **stack_b, 
									int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		operations(stack_a, stack_b, "rrr");
	}
}

static void	do_rr(t_stack **stack_a, t_stack **stack_b, 
									int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		operations(stack_a, stack_b, "rr");
	}
}

static void	do_ra(t_stack **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			operations(stack_a, NULL, "ra");
			(*cost)--;
		}
		else if (*cost < 0)
		{
			operations(stack_a, NULL, "rra");
			(*cost)++;
		}
	}
}

static void	do_rb(t_stack **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			operations(NULL, stack_b, "rb");
			(*cost)--;
		}
		else if (*cost < 0)
		{
			operations(NULL, stack_b, "rrb");
			(*cost)++;
		}
	}
}

void	move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rrr(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rr(stack_a, stack_b, &cost_a, &cost_b);
	do_ra(stack_a, &cost_a);
	do_rb(stack_b, &cost_b);
	operations(stack_a, stack_b, "pa");
}
