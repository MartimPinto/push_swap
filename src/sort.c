/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:36:09 by mcarneir          #+#    #+#             */
/*   Updated: 2023/09/01 13:45:46 by mcarneir         ###   ########.fr       */
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
		{
			swap(stack_a);
			ft_printf("sa\n");
		}
	}
}

/*void	sort3(t_stack **stack_a)
{
	t_stack	*node;
	
	node = *stack_a;
	
	if (node->nbr < node->next->next->nbr)
		{
			if (node->next->nbr < node->next->next->nbr)
			{	
				swap(stack_a);
				ft_printf("sa\n");
			}
			else if (node->next->nbr > node->next->next->nbr)
			{
				swap(stack_a);
				ft_printf("sa\n");
				rotate(stack_a);
				ft_printf("ra\n");
			}
		}
	else if (node->nbr > node->next->next->nbr)
	{
		if (node->next->nbr < node->next->next->nbr)
		{
			rotate(stack_a);
			ft_printf("ra\n");
		}
		else if (node->next->nbr > node->next->next->nbr)
		{
			if (node->nbr > node->next->next->nbr)
			{
				reverse_rotate(stack_a);
				ft_printf("rra\n");
			}
		}
	}
}*/
void	sort3(t_stack **stack_a)
{
	t_stack	*node;
	int	max_nbr;
	int	min_nbr;
	
	node = *stack_a;
	max_nbr = max(node);
	min_nbr = min(node);

	if (node->nbr == max_nbr)
	{
		if (node->next->nbr == min_nbr)
		{
			rotate(stack_a);
			ft_printf("ra\n");
		}
		else
		{
			swap(stack_a);
			ft_printf("sa\n");
			reverse_rotate(stack_a);
			ft_printf("rra\n");
		}
	}
	else if (node->nbr == min_nbr)
	{
		swap(stack_a);
		ft_printf("sa\n");
		rotate(stack_a);
		ft_printf("ra\n");
	}
	else
	{
		if (node->next->nbr == min_nbr)
		{
			swap(stack_a);
			ft_printf("sa\n");
		}
		else
		{
			reverse_rotate(stack_a);
			ft_printf("rra\n");
		}
	}
}

void	sort(t_stack **stack_a)
{
	if (check_sorted(*stack_a) != 0)
		return ;
	else if (ft_dlstsize(*stack_a) == 2)
		sort2(stack_a);
	else if (ft_dlstsize(*stack_a) == 3)
		sort3(stack_a);
}
