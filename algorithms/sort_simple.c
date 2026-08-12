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

int	sort_simple(t_stack *a, t_stack *b) // atualizar para retornar a quantidade de operações para utilizar no bench
{
	int	min_idx;
	int	rot;
	int count_op;

	count_op = 0;
	if (a->size <= 1)
		return (0);
	while (a->size > 0)
	{
		min_idx = stack_min_pos(a);
		if (min_idx <= a->size / 2)
		{
			rot = min_idx;
			while (rot--)
				count_op += ra(a);
		}
		else
		{
			rot = a->size - min_idx;
			while (rot--)
				count_op += rra(a);
		}
		count_op += pb(a, b);
	}
	while (b->size > 0)
		count_op += pa(a, b);
	return (count_op);
}
