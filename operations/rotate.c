/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:03:14 by sbanko            #+#    #+#             */
/*   Updated: 2026/08/12 14:19:27 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rotate(t_stack *s)
{
	t_node	*first_node;

	if (!s || s->size < 2)
		return ;
	first_node = stack_pop_top(s);
	stack_push_bottom(s, first_node);
}

void	ra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	rotate(a);
	inc_opcount(OP_RA);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	rotate(b);
	inc_opcount(OP_RB);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	if ((!a || a->size < 2) && (!b || b->size < 2))
		return ;
	rotate(a);
	rotate(b);
	inc_opcount(OP_RR);
	write(1, "rr\n", 3);
}
