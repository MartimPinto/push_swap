/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:00:20 by mcarneir          #+#    #+#             */
/*   Updated: 2023/09/11 13:31:25 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_nbr(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_repeat(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_value(char **str, int i)
{
	long	tmp;

	if (check_repeat(str) != 0)
		return (1);
	while (str[i])
	{
		tmp = atol(str[i]);
		if (check_nbr(str[i]) != 0)
			return (1);
		if (tmp < -2147483648 || tmp > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

int	parser(int argc, char **argv)
{
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	if (check_value(args, i) != 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc == 2)
		free_array(args);
	return (0);
}
