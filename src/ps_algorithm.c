/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaeys <bclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:59:43 by bclaeys           #+#    #+#             */
/*   Updated: 2024/09/16 16:04:04 by bclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	calc_list_len(t_node **list_top)
{
	t_node	*current;
	int		index;

	index = 1;
	current = (*list_top)->next;
	while (current != *list_top)
	{
		current = current->next;
		index++;
	}
	return (index);
}

float	calc_node_i(t_node **list_top, t_node *target)
{
	t_node	*current;
	int		index;

	index = 1;
	current = *list_top;
	while (current->next != *list_top)
	{
		if (current == target)
			break ;
		current = current->next;
		index++;
	}
	return (index);
}

void	push_up(t_node **target_node, t_node **top, float half, char c)
{
	while (*target_node != *top)
	{
		if (half > 2)
		{
			ps_rotate(top);
			if (c == 'a')
				ft_printf("ra\n");
			if (c == 'b')
				ft_printf("rb\n");
		}
		else
		{
			ps_rev_rotate(top);
			if (c == 'a')
				ft_printf("rra\n");
			if (c == 'b')
				ft_printf("rrb\n");
		}
	}
}

void	final_sort(t_node **node_a, t_node **node_b, int llb)
{
	t_node	*current;
	t_node	*highest_number;

	current = (*node_b)->next;
	highest_number = *node_b;
	while (current != *node_b)
	{
		if (highest_number->content < current->content)
			highest_number = current;
		current = current->next;
	}
	push_up(&highest_number, node_b, ((llb - 1) / (calc_node_i(node_b,
					highest_number) + 1)), 'b');
	current = *node_b;
	while (current->next != *node_b)
	{
		current = *node_b;
		current = current->next;
		ps_push(node_b, node_a);
		ft_printf("pa\n");
	}
	ps_push(node_b, node_a);
	ft_printf("pa\n");
}

void	ps_algorithm(t_node **node_a, t_node **node_b)
{
	t_node	*current_a;
	float	listlen_a;
	float	listlen_b;

	ps_push_highest_and_lowest(node_a, node_b);
	current_a = ps_push_cost_calc(node_a, node_b);
	while ((*node_a) != (*node_a)->next)
	{
		listlen_a = calc_list_len(node_a);
		listlen_b = calc_list_len(node_b);
		push_up(&current_a, node_a, ((listlen_a - 1) / (calc_node_i(node_a,
						current_a) + 1)), 'a');
		push_up(&(current_a->target_node->next), node_b, ((listlen_b - 1)
				/ (calc_node_i(node_b, current_a->target_node->next) + 1)),
			'b');
		ps_push(node_a, node_b);
		ft_printf("pb\n");
		current_a = ps_push_cost_calc(node_a, node_b);
	}
	push_up(&(current_a->target_node->next), node_b, ((listlen_b)
			/ (calc_node_i(node_b, current_a->target_node->next) + 1)),
		'b');
	ps_push(node_a, node_b);
	ft_printf("pb\n");
	final_sort(node_a, node_b, listlen_b);
}
