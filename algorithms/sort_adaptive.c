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

int	sort_adaptive(t_stack *a, t_stack *b)
{
	double	d;

	d = compute_disorder(a);
	if (d < 0.2)
		sort_simple(a, b);
	else if (d < 0.5)
		sort_medium(a, b);
	else
		sort_complex(a, b);
	return (0);
}
