/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:30:15 by mcarneir          #+#    #+#             */
/*   Updated: 2023/09/01 13:46:06 by mcarneir         ###   ########.fr       */
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
void	create_stack(t_stack **stack, int argc, char **argv);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
int	check_sorted(t_stack *stack_a);


//Operations//
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	push(t_stack **stack1, t_stack **stack2);

//Free//
void	free_array(char **arr);
void	free_stack(t_stack **stack);
void	free_all(t_stack **stack_a, t_stack **stack_b);

//Sort//
void	sort(t_stack **stack_a);
void	sort2(t_stack **stack_a);
void	sort3(t_stack **stack_a);

#endif