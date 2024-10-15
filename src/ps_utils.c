/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaeys <bclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:09:27 by bclaeys           #+#    #+#             */
/*   Updated: 2024/09/09 19:24:17 by bclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ps_add_node(t_node *first_node, t_node *prev_node, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		first_node->next = NULL;
		ps_free_and_exit(first_node);
		exit(-1);
	}
	new_node->content = value;
	new_node->next = first_node;
	new_node->prev = prev_node;
	first_node->prev = new_node;
	prev_node->next = new_node;
	return (new_node);
}

t_node	*ps_create_list(int argc, char **argv)
{
	t_node	*current;
	t_node	*top_a;
	int		i;

	i = 2;
	if (argc <= 2)
		exit(-1);
	top_a = malloc(sizeof(t_node));
	if (!top_a)
		exit(-1);
	top_a->content = ft_atoi(argv[1]);
	current = top_a;
	while (i < argc)
	{
		current = ps_add_node(top_a, current, ft_atoi(argv[i]));
		i++;
	}
	return (top_a);
}
