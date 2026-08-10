/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PersonB <personb@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 00:00:00 by PersonB           #+#    #+#             */
/*   Updated: 2026/07/19 00:00:00 by PersonB          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

void	sort_simple(t_stack *a, t_stack *b)
{
	int	min_idx;
	int	rot;

	if (a->size <= 1)
		return ;
	while (a->size > 0)
	{
		min_idx = stack_min_pos(a);
		if (min_idx <= a->size / 2)
		{
			rot = min_idx;
			while (rot--)
				ra(a);
		}
		else
		{
			rot = a->size - min_idx;
			while (rot--)
				rra(a);
		}
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
}
