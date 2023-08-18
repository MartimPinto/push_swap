/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:30:15 by mcarneir          #+#    #+#             */
/*   Updated: 2023/08/18 17:49:54 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libs/libft/libft.h"

typedef struct s_stack
{
	int	nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
	
}	t_stack;

//Argument Validation//

int	check_nbr(char *str);
int	check_repeat(char **str);
int	check_value(char **str, int i);
int	parser(int argc, char **argv);

//Utils//

int	ft_dlstsize(t_stack *lst);
t_stack	*ft_dlstlast(t_stack *lst);
void *ft_dlstadd_front(t_stack **lst, t_stack *new);
void	ft_dlstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_dlstnew(int nbr);
int	max(t_stack *lst);
int	min(t_stack *lst);

#endif