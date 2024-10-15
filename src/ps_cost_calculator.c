/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cost_calculator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaeys <bclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:19:09 by bclaeys           #+#    #+#             */
/*   Updated: 2024/09/05 19:15:39 by bclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_distance_to_top(t_node **node_top, t_node *to_search)
{
	float	i;
	float	position;
	t_node	*current;

	i = 1;
	position = 0;
	current = (*node_top)->next;
	while (current->content != (*node_top)->content)
	{
		if (current == to_search)
			position = i;
		current = current->next;
		i++;
	}
	if (position > i / 2)
		position = i - position + 1;
	return (position);
}

void	ps_find_target(t_node **node_from_a, t_node **node_from_b)
{
	t_node	*current;
	long	distance_to_max;

	current = (*node_from_b)->next;
	if (((*node_from_b)->content - (*node_from_a)->content) >= 0)
		distance_to_max = (*node_from_b)->content - (*node_from_a)->content;
	else
		distance_to_max = LONG_MAX;
	(*node_from_a)->target_node = *node_from_b;
	while (current != *node_from_b)
	{
		if ((current->content - (*node_from_a)->content < distance_to_max)
			&& current->content - (*node_from_a)->content > 0)
		{
			distance_to_max = (current->content - (*node_from_a)->content);
			(*node_from_a)->target_node = current;
		}
		current = current->next;
	}
}

t_node	*ps_push_cost_calc(t_node **node_a, t_node **node_b)
{
	t_node	*current;
	t_node	*lowest_cost_a;

	current = (*node_a)->next;
	ps_find_target(node_a, node_b);
	(*node_a)->cost = (find_distance_to_top(node_a, *node_a)
			+ find_distance_to_top(node_b, (*node_a)->target_node->next));
	while (current != *node_a)
	{
		ps_find_target(&current, node_b);
		current->cost = (find_distance_to_top(node_a, current)
				+ find_distance_to_top(node_b, (current)->target_node->next));
		current = current->next;
	}
	lowest_cost_a = *node_a;
	current = (*node_a)->next;
	while (current != *node_a)
	{
		if (current->cost < lowest_cost_a->cost)
			lowest_cost_a = current;
		current = current->next;
	}
	return (lowest_cost_a);
}
