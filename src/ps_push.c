/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaeys <bclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:37:17 by bclaeys           #+#    #+#             */
/*   Updated: 2024/09/02 12:31:17 by bclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	first_b_push(t_node **src, t_node **dest, t_node *temp)
{
	(*src)->prev->next = (*src)->next;
	(*src)->next->prev = (*src)->prev;
	(*src)->next = *src;
	(*src)->prev = *src;
	*dest = *src;
	*src = temp;
	return (0);
}

static int	one_node_left(t_node **src, t_node **dest)
{
	(*src)->next = *dest;
	(*src)->prev = (*dest)->prev;
	(*dest)->prev->next = *src;
	(*dest)->prev = *src;
	*dest = *src;
	(*src) = NULL;
	return (0);
}

static int	two_nodes_left(t_node **src, t_node **dest, t_node *temp)
{
	(*src)->prev->next = (*src)->next;
	(*src)->next->prev = (*src)->prev;
	(*src)->next = *dest;
	(*src)->prev = (*dest)->prev;
	(*dest)->prev->next = *src;
	(*dest)->prev = *src;
	*dest = *src;
	*src = temp;
	(*src)->next = *src;
	return (0);
}

int	ps_push(t_node **src, t_node **dest)
{
	t_node	*temp;

	if (!*src)
		return (-1);
	temp = (*src)->next;
	if (!*dest)
		return (first_b_push(src, dest, temp));
	if ((*src)->next == *src)
		return (one_node_left(src, dest));
	if ((*src)->next->next == *src)
		return (two_nodes_left(src, dest, temp));
	else
	{
		(*src)->prev->next = (*src)->next;
		(*src)->next->prev = (*src)->prev;
		(*src)->next = *dest;
		(*src)->prev = (*dest)->prev;
		(*dest)->prev->next = *src;
		(*dest)->prev = *src;
		*dest = *src;
		*src = temp;
	}
	return (0);
}
