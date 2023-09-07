/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:22:59 by mcarneir          #+#    #+#             */
/*   Updated: 2023/09/07 17:07:41 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

/*int	max(t_stack *lst)
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
}*/

int	min(t_stack *lst)
{
	int	i;
	
	i = lst->nbr;
	while(lst)
	{
		if (lst->nbr < i)
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

void	operations(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (ft_strncmp("sa", op, 3) == 0)
		swap(stack_a);
	else if (ft_strncmp("sb", op, 3) == 0)
		swap(stack_b);
	else if (ft_strncmp("pa", op, 3) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp("pb", op, 3) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp("ra", op, 3) == 0)
		rotate(stack_a);
	else if (ft_strncmp("rb", op, 3) == 0)
		rotate(stack_b);
	else if (ft_strncmp("rr", op, 3) == 0)
		rotate_both(stack_a, stack_b);
	else if (ft_strncmp("rra", op, 4) == 0)
		reverse_rotate(stack_a);
	else if (ft_strncmp("rrb", op, 4) == 0)
		reverse_rotate(stack_b);
	else if (ft_strncmp("rrr", op, 4) == 0)
		reverse_rotate_both(stack_a, stack_b);
	ft_printf("%s\n", op);
}
int	abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
