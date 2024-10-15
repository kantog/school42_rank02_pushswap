/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaeys <bclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 23:26:42 by bclaeys           #+#    #+#             */
/*   Updated: 2024/09/16 16:16:50 by bclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_free_and_exit(t_node *first_node)
{
	t_node	*current;
	t_node	*tmp;

	if (!first_node)
		exit(-1);
	if (!(first_node->next))
	{
		free(first_node);
		exit(-1);
	}
	current = first_node->next;
	while (current && current != first_node)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	if (first_node)
		free(first_node);
}

void	error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}
