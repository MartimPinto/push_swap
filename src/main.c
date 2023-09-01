/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:36:43 by mcarneir          #+#    #+#             */
/*   Updated: 2023/09/01 13:33:38 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_stack **stack_a;
	t_stack **stack_b;

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
	sort(stack_a);
	
    return 0;
}