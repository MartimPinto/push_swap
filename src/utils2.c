/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:22:59 by mcarneir          #+#    #+#             */
/*   Updated: 2023/09/01 13:28:02 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

int	max(t_stack *lst)
{
	int	i;

	i = lst->nbr;
	while(lst)
	{
		if (lst->nbr > i)
			i = lst->nbr;
		lst = lst->next;
	}
	return (i);
}

int	min(t_stack *lst)
{
	int	i;
	
	i = lst->nbr;
	while(lst)
	{
		if (i < lst->nbr)
			i = lst->nbr;
		lst = lst->next;
	}
	return (i);
}
void	create_stack(t_stack **stack, int argc, char **argv)
{
	t_stack *node;
	char	**args;
	int	i;

	i = 0;
	*stack = NULL;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		node = ft_dlstnew(ft_atoi(args[i]));
		ft_dlstadd_back(stack, node);
		i++;
	}
	if (argc == 2)
	{
		free_array(args);
	}
}
void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a = stack_a;
	t_stack	*current_b = stack_b;
	
	ft_printf("Stack A Contents:\n");
	while (current_a)
	{
		ft_printf("%d\n", current_a->nbr);
		current_a = current_a->next;
	}
    ft_printf("\nStack B Contents:\n");
    while (current_b)
	{
		ft_printf("%d\n", current_b->nbr);
		current_b = current_b->next;
	}
}
int	check_sorted(t_stack *stack_a)
{
	int	i;

	if (stack_a == NULL)
		return (1);	
	i = stack_a->nbr;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (i > stack_a->nbr)
			return (0);
		i = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (1);
}
