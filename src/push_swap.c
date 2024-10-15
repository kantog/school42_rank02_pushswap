/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaeys <bclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:32:57 by bclaeys           #+#    #+#             */
/*   Updated: 2024/09/09 17:19:51 by bclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	ps_print_list(t_node *top_node, char c)
{
	t_node	*current_node;

	if (!top_node)
	{
		ft_printf("list %c is empty\n", c);
		return ;
	}
	current_node = top_node->next;
	ft_printf("list %c: %i ", c, top_node->content);
	while (current_node != top_node)
	{
		ft_printf("%i ", current_node->content);
		current_node = current_node->next;
	}
	ft_printf(" top node again: %i\n", current_node->content);
}
*/
int	main(int argc, char **argv)
{
	t_node	*top_node_a;
	t_node	*top_node_b;

	top_node_b = NULL;
	ps_error_manager(argc, argv);
	top_node_a = ps_create_list(argc, argv);
	if (!(ps_check_sorted(top_node_a)))
	{
		ps_free_and_exit(top_node_a);
		exit(-1);
	}
	if (argc >= 3 && argc <= 6)
	{
		ps_hardcodes(&top_node_a, &top_node_b, argc);
		ps_free_and_exit(top_node_a);
		exit(-1);
	}
	ps_algorithm(&top_node_a, &top_node_b);
	ps_free_and_exit(top_node_a);
	ps_free_and_exit(top_node_b);
}
