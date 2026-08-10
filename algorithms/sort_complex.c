/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PersonB <personb@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 00:00:00 by PersonB           #+#    #+#             */
/*   Updated: 2026/07/19 00:00:00 by PersonB          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

void	sort_complex(t_stack *a, t_stack *b)
{
	int	max_bit;
	int	bit;
	int	cnt;
	int	i;

	max_bit = 0;
	while ((a->size - 1) >> max_bit)
		max_bit++;
	bit = 0;
	while (bit < max_bit)
	{
		cnt = a->size;
		i = 0;
		while (i < cnt)
		{
			if (((a->top->index >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}

