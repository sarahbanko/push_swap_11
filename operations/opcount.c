/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcount.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperei <adrperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 11:30:00 by adrperei          #+#    #+#             */
/*   Updated: 2026/08/12 11:30:00 by adrperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static t_opcount	*g_counter;

void	set_opcount_ptr(t_opcount *c)
{
	g_counter = c;
}

void	inc_opcount(int type)
{
	if (!g_counter)
		return ;
	if (type == OP_SA)
		g_counter->sa++;
	else if (type == OP_SB)
		g_counter->sb++;
	else if (type == OP_SS)
		g_counter->ss++;
	else if (type == OP_PA)
		g_counter->pa++;
	else if (type == OP_PB)
		g_counter->pb++;
	else if (type == OP_RA)
		g_counter->ra++;
	else if (type == OP_RB)
		g_counter->rb++;
	else if (type == OP_RR)
		g_counter->rr++;
	else if (type == OP_RRA)
		g_counter->rra++;
	else if (type == OP_RRB)
		g_counter->rrb++;
	else if (type == OP_RRR)
		g_counter->rrr++;
}
