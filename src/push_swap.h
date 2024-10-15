/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaeys <bclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:39:43 by bclaeys           #+#    #+#             */
/*   Updated: 2024/09/16 16:17:04 by bclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				content;
	int				cost;
	struct s_node	*target_node;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

t_node	*ps_create_list(int argc, char **argv);
void	ps_free_and_exit(t_node *first_node);
int		ps_push(t_node **src, t_node **dest);
int		ps_rotate(t_node **src);
int		ps_rev_rotate(t_node **src);
int		ps_swap(t_node **src);
void	ps_push_highest_and_lowest(t_node **node_a, t_node **node_b);
void	ps_algorithm(t_node **node_a, t_node **node_b);
int		find_index(t_node **node_top, t_node *to_search);
t_node	*ps_push_cost_calc(t_node **node_a, t_node **node_b);
void	ps_print_list(t_node *top_node, char c);
float	calc_list_len(t_node **list_top);
void	ps_find_target(t_node **node_from_a, t_node **node_from_b);
float	calc_node_i(t_node **list_top, t_node *target);
void	push_up(t_node **target_node, t_node **top, float half, char c);
void	ps_error_manager(int argc, char **argv);
int		ps_check_sorted(t_node *node_a);
void	ps_hardcodes(t_node **top_a, t_node **top_b, int argc);
void	error_and_exit(void);

#endif
