/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:09:22 by mcarneir          #+#    #+#             */
/*   Updated: 2023/08/31 16:12:23 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	second = first->next;
	if (ft_dlstsize(*stack) < 2)
		return ;
	first->next = second->next;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	ft_dlstadd_front(stack, second);
	*stack = second;
}

void	rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*tmp;

	if (ft_dlstsize(*stack) < 2)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tail = ft_dlstlast(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*node;
	
	if (ft_dlstsize(*stack) < 2)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	node = ft_dlstlast(*stack);
	ft_dlstadd_front(stack, node);
	tmp->next = NULL;
}

void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*node1;
	t_stack	*node2;

	if(*stack1)
	{
		node1 = *stack1;
		node2 = ft_dlstnew((*stack1)->nbr);
		if (*stack2)
			ft_dlstadd_front(stack2, node2);
		else
			*stack2 = node2;
		*stack1 = (*stack1)->next;
		free(node1);
	}
}