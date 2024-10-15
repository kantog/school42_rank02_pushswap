/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaeys <bclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:38:42 by bclaeys           #+#    #+#             */
/*   Updated: 2024/09/16 16:25:38 by bclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_duplicate_check(int argc, char **argv)
{
	int	arg_start;
	int	arg_number;
	int	i;

	arg_start = 1;
	arg_number = 2;
	i = 0;
	while (arg_start < argc)
	{
		while (arg_number < argc)
		{
			if (ft_atoi(argv[arg_start]) == ft_atoi(argv[arg_number]))
			{
				write(2, "Error\n", 6);
				exit(-1);
			}
			arg_number++;
		}
		arg_start++;
		arg_number = arg_start + 1;
	}
}

int	ps_maxint_check(const char *str)
{
	int					i;
	unsigned long long	temp_value;

	i = 0;
	temp_value = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		temp_value = temp_value * 10 + (str[i] - 48);
		if (temp_value > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

void	ps_error_manager(int argc, char **argv)
{
	int	arg_number;
	int	digit;

	arg_number = 1;
	digit = 0;
	while (arg_number < argc)
	{
		if (argv[arg_number][digit] == '-' || argv[arg_number][digit] == '+')
			digit++;
		if (!(argv[arg_number][digit]))
			error_and_exit();
		while (argv[arg_number][digit])
		{
			if (!(ft_isdigit(argv[arg_number][digit++])))
				error_and_exit();
		}
		if (!(ps_maxint_check(argv[arg_number++])))
			error_and_exit();
		digit = 0;
	}
	ps_duplicate_check(argc, argv);
}

int	ps_check_sorted(t_node *node_a)
{
	t_node	*current;

	current = node_a;
	while (current->next != node_a)
	{
		if (current->content > current->next->content)
			return (1);
		current = current->next;
	}
	return (0);
}
