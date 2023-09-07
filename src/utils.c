/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:15:14 by mcarneir          #+#    #+#             */
/*   Updated: 2023/09/07 17:16:40 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_dlstsize(t_stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
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
	node->index = 0;
	node->pos = -1;
	node->target_pos = -1;
	node->cost_a = -1;
	node->cost_b = -1;
	return (node);
}
