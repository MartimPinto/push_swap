/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:30:15 by mcarneir          #+#    #+#             */
/*   Updated: 2023/09/07 17:05:33 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libs/libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int	nbr;
	int	index;
	int	pos;
	int	target_pos;
	int	cost_a;
	int	cost_b;
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
int	min(t_stack *lst);
void	create_stack(t_stack **stack, int argc, char **argv);
int	check_sorted(t_stack *stack_a);
void	operations(t_stack **stack_a, t_stack **stack_b, char *op);
void	assign_index(t_stack **stack_a, int	stack_size);
int	abs(int n);

//Operations//
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	push(t_stack **stack1, t_stack **stack2);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_both(t_stack	**stack_a, t_stack **stack_b);
void	move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);

//Free//
void	free_array(char **arr);
void	free_stack(t_stack **stack);
void	free_all(t_stack **stack_a, t_stack **stack_b);

//Sort//
void	sort(t_stack **stack_a, t_stack	**stack_b);
void	small_sort(t_stack **stack_a, t_stack	**stack_b);
void	sort2(t_stack **stack_a);
void	sort3(t_stack **stack_a);
void	sort5(t_stack **stack_a, t_stack **stack_b);
void push_min_b(t_stack **stack_a, t_stack **stack_b);

//position//
int	lowest_index_pos(t_stack	**stack);
void	get_target_pos(t_stack **stack_a, t_stack **stack_b);

//cost//
void	get_cost(t_stack **stack_a, t_stack **stack_b);
void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b);


#endif