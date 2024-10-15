/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaeys <bclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:49:19 by bclaeys           #+#    #+#             */
/*   Updated: 2024/09/03 18:49:26 by bclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_swap(t_node **src)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = (*src)->next;
	temp2 = (*src)->next->next;
	if ((*src)->next->next == *src)
		return (ps_rotate(src));
	(*src)->next->next->prev = *src;
	(*src)->prev->next = (*src)->next;
	(*src)->next->prev = (*src)->prev;
	(*src)->next->next = *src;
	(*src)->prev = (*src)->next;
	(*src)->next = temp2;
	*src = temp1;
	return (0);
}
