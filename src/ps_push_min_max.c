/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_min_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaeys <bclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:59:43 by bclaeys           #+#    #+#             */
/*   Updated: 2024/09/16 16:04:02 by bclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_highest_number(t_node **node_a)
{
	t_node	*top_a;
	t_node	*current;

	top_a = *node_a;
	current = (*node_a)->next;
	while (current != *node_a)
	{
		if (top_a->content < current->content)
			top_a = current;
		current = current->next;
	}
	return (top_a);
}

void	ps_push_highest_and_lowest(t_node **node_a, t_node **node_b)
{
	t_node	*top_a;
	float	list_len_a;

	list_len_a = calc_list_len(node_a);
	top_a = find_highest_number(node_a);
	push_up(&top_a, node_a, ((list_len_a - 1) / (calc_node_i(node_a, top_a)
				+ 1)), 'a');
	ps_push(node_a, node_b);
	ft_printf("pb\n");
	ps_push(node_a, node_b);
	ft_printf("pb\n");
}
