/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:09:22 by mcarneir          #+#    #+#             */
/*   Updated: 2023/09/11 13:23:14 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp_nbr;
	int	tmp_index;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp_nbr = stack->nbr;
	stack->nbr = stack->next->nbr;
	stack->next->nbr = tmp_nbr;
	tmp_index = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp_index;
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->prev = ft_dlstlast(*stack);
	tmp->next = NULL;
	tmp->prev->next = tmp;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*before_tail;
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tail = ft_dlstlast(*stack);
	before_tail = tail->prev;
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	tmp->prev = tail;
	before_tail->next = NULL;
}

void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp;

	if (*stack1 == NULL)
		return ;
	tmp = *stack1;
	*stack1 = (*stack1)->next;
	if (*stack1 != NULL)
		(*stack1)->prev = NULL;
	tmp->prev = NULL;
	tmp->next = *stack2;
	if (*stack2 != NULL)
		(*stack2)->prev = tmp;
	*stack2 = tmp;
}
