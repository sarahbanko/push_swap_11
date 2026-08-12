/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PersonB <personb@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 00:00:00 by PersonB           #+#    #+#             */
/*   Updated: 2026/08/12 11:01:36 by adrperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

int	sort_simple(t_stack *a, t_stack *b)
{
	int	min_idx;
	int	rot;

	if (a->size <= 1)
		return (0);
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
		pb(b, a);
	}
	while (b->size > 0)
		pa(a, b);
	return (0);
}
