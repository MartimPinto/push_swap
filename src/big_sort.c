/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:11:06 by mcarneir          #+#    #+#             */
/*   Updated: 2023/09/11 13:16:54 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_to_b_till_3(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = ft_dlstsize(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			operations(stack_a, stack_b, "pb");
			pushed++;
		}
		else
			operations(stack_a, NULL, "ra");
		i++;
	}
	while (stack_size - pushed > 3)
	{
		operations(stack_a, stack_b, "pb");
		pushed++;
	}
}

static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = ft_dlstsize(*stack_a);
	lowest_pos = lowest_index_pos(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			operations(stack_a, NULL, "rra");
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			operations(stack_a, NULL, "ra");
			lowest_pos--;
		}
	}
}

void	sort(t_stack **stack_a, t_stack	**stack_b)
{
	push_to_b_till_3(stack_a, stack_b);
	if (check_sorted(*stack_a) == 0)
		small_sort(stack_a, stack_b);
	while (*stack_b)
	{
		get_target_pos(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (check_sorted(*stack_a) == 0)
		shift_stack(stack_a);
}
