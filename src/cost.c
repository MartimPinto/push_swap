/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:04:14 by mcarneir          #+#    #+#             */
/*   Updated: 2023/09/06 13:46:03 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	int	size_a;
	int	size_b;

	current_a = *stack_a;
	current_b = *stack_b;
	size_a = ft_dlstsize(*stack_a);
	size_b = ft_dlstsize(*stack_b);
	while (current_b)
	{
		current_b->cost_b = current_b->pos;
		if (current_b->pos > size_b / 2)
			current_b->cost_b = (size_b - current_b->pos) * -1;
		current_b->cost_a = current_b->target_pos;
		if (current_b->target_pos > size_a / 2)
			current_b->cost_a = (size_a - current_b->target_pos) * -1;
		current_b = current_b ->next;
	}
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int	cheap;
	int	cost_a;
	int	cost_b;
	
	current = *stack_b;
	cheap = INT_MAX;
	while (current)
	{
		if (abs(current->cost_a) + abs(current->cost_b) < abs(cheap))
		{
			cheap = abs(current->cost_b) + abs(current->cost_a);
			cost_a = current->cost_a;
			cost_b = current->cost_b;
		}
		current = current->next;
	}
	move(stack_a, stack_b, cost_a, cost_b);
}