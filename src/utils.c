/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:15:14 by mcarneir          #+#    #+#             */
/*   Updated: 2023/09/01 12:23:08 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_dlstsize(t_stack *lst)
{
	int	i;
	t_stack	*current;

	i = 0;
	current = lst;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

t_stack	*ft_dlstlast(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void *ft_dlstadd_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return NULL;
	if (!lst)
	{
		*lst = new;
		return *lst;
	}
	new->next = *lst;
	new->prev = NULL;
	if (*lst)
		(*lst)->prev = new;
	*lst = new;
	return *lst;
}

void	ft_dlstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*replace;
	
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return;
	}
	replace = ft_dlstlast(*lst);
	replace->next = new;
	new->prev = replace;
}

t_stack	*ft_dlstnew(int nbr)
{
	t_stack *node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = nbr;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}