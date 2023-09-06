/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:42:22 by mcarneir          #+#    #+#             */
/*   Updated: 2023/09/05 12:55:40 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_index(t_stack **stack_a, int	stack_size)
{
	t_stack	*current;
	t_stack	*highest;
	int	value;

	while(--stack_size > 0)
	{
		current = *stack_a;
		value = INT_MIN;
		highest = NULL;
		while (current)
		{
			if (current->nbr == INT_MIN && current->index == 0)
				current->index = 1;
			if (current->nbr > value && current->index == 0)
			{
				value = current->nbr;
				highest = current;
				current = *stack_a;
			}
			else
				current = current->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
