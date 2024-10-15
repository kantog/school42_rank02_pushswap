/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaeys <bclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:03:00 by bclaeys           #+#    #+#             */
/*   Updated: 2024/09/03 18:10:27 by bclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_rotate(t_node **src)
{
	if (!*src)
		return (-1);
	*src = (*src)->next;
	return (0);
}

int	ps_rev_rotate(t_node **src)
{
	if (!*src)
		return (-1);
	*src = (*src)->prev;
	return (0);
}
