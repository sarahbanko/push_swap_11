/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PersonB <personb@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 00:00:00 by PersonB           #+#    #+#             */
/*   Updated: 2026/07/19 00:00:00 by PersonB          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

int	sort_adaptive(t_stack *a, t_stack *b) // atualizar para retornar a quantidade de operações para utilizar no bench
{
	double	d;
	int count_op;

	count_op = 0;
	d = compute_disorder(a);
	if (d < 0.2)
		count_op = sort_simple(a, b);
	else if (d < 0.5)
		count_op = sort_medium(a, b);
	else
		count_op = sort_complex(a, b);
	
	return (count_op);
}
