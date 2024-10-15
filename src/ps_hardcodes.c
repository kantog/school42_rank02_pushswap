/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hardcodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaeys <bclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:23:54 by bclaeys           #+#    #+#             */
/*   Updated: 2024/09/16 16:23:20 by bclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_lowest_number(t_node **node_a)
{
	t_node	*top_a;
	t_node	*current;

	top_a = *node_a;
	current = (*node_a)->next;
	while (current != *node_a)
	{
		if (top_a->content > current->content)
			top_a = current;
		current = current->next;
	}
	return (top_a);
}

void	ps_handle_321_231(t_node **top_a)
{
	if ((*top_a)->content > (*top_a)->next->content)
	{
		ps_swap(top_a);
		ft_printf("sa\n");
	}
	ps_rev_rotate(top_a);
	ft_printf("rra\n");
}

void	ps_handle_three(t_node **top_a, t_node *lowest_a)
{
	if (calc_node_i(top_a, lowest_a) == 1)
	{
		ps_rev_rotate(top_a);
		ft_printf("rra\n");
		ps_swap(top_a);
		ft_printf("sa\n");
	}
	else if (calc_node_i(top_a, lowest_a) == 2)
	{
		if ((*top_a)->content > lowest_a->next->content)
		{
			ps_rev_rotate(top_a);
			ft_printf("rra\n");
			ps_rev_rotate(top_a);
			ft_printf("rra\n");
		}
		else
		{
			ps_swap(top_a);
			ft_printf("sa\n");
		}
	}
	else
		ps_handle_321_231(top_a);
}

void	ps_fourfive(t_node **t_a, t_node **t_b, t_node *l_a, int argc)
{
	if (argc == 6)
	{
		ps_push(t_a, t_b);
		ft_printf("pb\n");
	}
	l_a = find_lowest_number(t_a);
	if (ps_check_sorted(*t_a) == 1)
		ps_handle_three(t_a, l_a);
	ps_find_target(t_b, t_a);
	push_up(&(*t_b)->target_node, t_a, (calc_list_len(t_a)
			/ (calc_node_i(t_a, (*t_b)->target_node) + 1)), 'a');
	ps_push(t_b, t_a);
	ft_printf("pa\n");
	if (argc == 6)
	{
		ps_find_target(t_b, t_a);
		if ((*t_b)->target_node->content < (*t_b)->content)
			(*t_b)->target_node = find_lowest_number(t_a);
		push_up(&(*t_b)->target_node, t_a, (calc_list_len(t_a) - 1
				/ (calc_node_i(t_a, (*t_b)->target_node) + 1)), 'a');
		ps_push(t_b, t_a);
		ft_printf("pa\n");
	}
	*t_b = find_lowest_number(t_a);
	push_up(t_b, t_a, (calc_list_len(t_a) / calc_node_i(t_a, *t_b) + 1), 'a');
}

void	ps_hardcodes(t_node **top_a, t_node **top_b, int argc)
{
	t_node	*lowest_a;

	lowest_a = find_lowest_number(top_a);
	if (argc == 3)
	{
		ps_swap(top_a);
		ft_printf("ra\n");
	}
	if (argc == 4)
		ps_handle_three(top_a, lowest_a);
	if (argc == 5 || argc == 6)
	{
		ps_push(top_a, top_b);
		ft_printf("pb\n");
		ps_fourfive(top_a, top_b, lowest_a, argc);
	}
}
