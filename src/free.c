/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:18:17 by mcarneir          #+#    #+#             */
/*   Updated: 2023/09/11 14:38:27 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free (arr);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*node;

	node = (*stack);
	while (node)
	{
		tmp = node;
		node = node->next;
		free (tmp);
	}
	*stack = NULL;
}

void	free_all(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a)
	{
		free_stack(stack_a);
		free(stack_a);
	}
	if (stack_b)
	{
		free_stack(stack_b);
		free(stack_b);
	}
}
