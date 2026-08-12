/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:01:59 by sbanko            #+#    #+#             */
/*   Updated: 2026/08/12 14:20:53 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	swap(t_stack *s)
{
	t_node	*temp;
	t_node	*temp_2;

	if (!s || s->size < 2)
		return ;
	temp = stack_pop_top(s);
	temp_2 = stack_pop_top(s);
	stack_push_top(s, temp);
	stack_push_top(s, temp_2);
}

void	sa(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	swap(a);
	inc_opcount(OP_SA);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	swap(b);
	inc_opcount(OP_SB);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	if (a->size < 2 && b->size < 2)
		return ;
	swap(a);
	swap(b);
	inc_opcount(OP_SS);
	write(1, "ss\n", 3);
}
