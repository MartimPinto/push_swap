/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:22:59 by mcarneir          #+#    #+#             */
/*   Updated: 2023/08/18 14:22:56 by mcarneir         ###   ########.fr       */
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
