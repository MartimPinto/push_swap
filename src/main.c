/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:36:43 by mcarneir          #+#    #+#             */
/*   Updated: 2023/09/11 14:37:44 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_swap(t_stack	**stack_a, t_stack	**stack_b, int stack_size)
{
	if (stack_size <= 5 && check_sorted(*stack_a) == 0)
		small_sort(stack_a, stack_b);
	else if (stack_size > 5 && check_sorted(*stack_a) == 0)
		sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	int		stack_size;

	if (argc < 2)
		return (1);
	if (parser(argc, argv))
		return (1);
	stack_a = malloc(sizeof(t_stack *));
	stack_b = malloc(sizeof(t_stack *));
	if (!stack_a || !stack_b)
	{
		free_all(stack_a, stack_b);
		return (1);
	}
	*stack_a = NULL;
	*stack_b = NULL;
	create_stack(stack_a, argc, argv);
	stack_size = ft_dlstsize(*stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(stack_a, stack_b, stack_size);
	free_all(stack_a, stack_b);
	return (0);
}
