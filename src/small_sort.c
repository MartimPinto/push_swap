/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:36:09 by mcarneir          #+#    #+#             */
/*   Updated: 2023/09/06 16:54:15 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort2(t_stack **stack_a)
{
	t_stack	*node;
	
	if (check_sorted(*stack_a) != 0)
		return ;
	node = *stack_a;
	if (node && node->next)
	{
		if (node->nbr > node->next->nbr)
			operations(stack_a, NULL, "sa");
	}
}

void	sort3(t_stack **stack_a)
{
	t_stack	*node;
	
	node = *stack_a;
	if (node->next->next->nbr > node->next->nbr)
	{
		if (node->nbr < node->next->next->nbr)
			operations(stack_a, NULL, "sa");
		else
			operations(stack_a, NULL, "ra");
	}
	else
	{ 
		if (node->next->next->nbr < node->nbr)
		{
			if(node->nbr > node->next->nbr)
				operations(stack_a, NULL, "sa");
			operations(stack_a, NULL, "rra");
		}
		else
		{
			operations(stack_a, NULL, "sa");
			operations(stack_a, NULL, "ra");
		}
	}
}
void push_min_b(t_stack **stack_a, t_stack **stack_b)
{
	int min_nbr;
	
	min_nbr = min(*stack_a);
	
	while ((*stack_a)->nbr != min_nbr)
	{
		if ((*stack_a)->nbr != min_nbr 
			&& (*stack_a)->next->nbr != min_nbr)
				operations(stack_a, NULL, "rra");
		else
			operations(stack_a, NULL, "ra");
	}
	operations(stack_a, stack_b, "pb");
}

void	sort5(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_dlstsize(*stack_a) == 5)
		push_min_b(stack_a, stack_b);
	push_min_b(stack_a, stack_b);
	if (check_sorted(*stack_a) == 0)
		sort3(stack_a);
	operations(stack_b, stack_a, "pa");
	operations(stack_b, stack_a, "pa");
}

void	small_sort(t_stack **stack_a, t_stack	**stack_b)
{
	if (ft_dlstsize(*stack_a) == 2)
		sort2(stack_a);
	else if (ft_dlstsize(*stack_a) == 3)
		sort3(stack_a);
	else if (ft_dlstsize(*stack_a) == 5 || ft_dlstsize(*stack_a) == 4)
		sort5(stack_a, stack_b);
}
