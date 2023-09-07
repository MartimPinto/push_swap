/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:11:17 by mcarneir          #+#    #+#             */
/*   Updated: 2023/09/07 17:26:40 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	get_position(t_stack **stack)
{
	t_stack	*current;
	int	i;

	current = *stack;
	i = 0;
	while (current)
	{
		current->pos = i;
		current = current->next;
		i++;
	}
}

int	lowest_index_pos(t_stack	**stack)
{
	t_stack	*current;
	int	lowest_index;
	int	lowest_pos;

	current = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = current->pos;
	while (current)
	{
		if (current->index < lowest_index)
		{
			lowest_index = current->index;
			lowest_pos = current->pos;
		}
		current = current->next;
	}
	return (lowest_pos);
}

static int	get_target(t_stack **stack_a, int	b_idx, int tgt_index, int tgt_pos)
{
	t_stack	*current;

	current = *stack_a;
	while (current)
	{
		if (current->index > b_idx && current->index < tgt_index)
		{
			tgt_index = current->index;
			tgt_pos = current->pos;
		}
		current = current->next;
	}
	if (tgt_index != INT_MAX)
		return (tgt_pos);
	current = *stack_a;
	while (current)
	{
		if (current->index < tgt_index)
		{
			tgt_index = current->index;
			tgt_pos = current->pos;
		}
		current = current->next;
	}
	return (tgt_pos);
}

void	get_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_b;
	int	tgt_pos;
	current_b = *stack_b;
	get_position(stack_a);
	get_position(stack_b);
	tgt_pos = 0;
	while (current_b)
	{
		tgt_pos = get_target(stack_a, current_b->index, INT_MAX, tgt_pos);
		current_b->target_pos = tgt_pos;
		current_b = current_b->next;
	}
}
