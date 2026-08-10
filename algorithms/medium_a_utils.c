/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_a_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:30:23 by sbanko            #+#    #+#             */
/*   Updated: 2026/08/10 14:01:15 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

int square_root(int n)
{
    int root;

    if (n <= 0)
        return (0);
    root = 1;
    while (root <= n / root) 
        root++;
    return (root - 1);
}

static int	find_top_distance_a(t_stack *a, int start, int end)
{
	t_node *current;
	int	distance;

	current = a->top;
	distance = 0;
	while (!(current->index >= start && current->index <= end))
	{
		distance++;
		current = current->next;
	}
	return (distance);
}

static int	find_bottom_distance_a(t_stack *a, int start, int end)
{
	t_node *current;
	int	distance;

	current = a->top->prev;
	distance = 1;
	while (!(current->index >= start && current->index <= end))
	{
		distance++;
		current = current->prev;
	}
	return (distance);
}

static int	move_chunk_to_top_a(t_stack *a, int start, int end)
{
	int	count_op;

	count_op = 0;
	if (find_top_distance_a(a, start, end)
		< find_bottom_distance_a(a, start, end))
	{
		while (!(a->top->index >= start
				&& a->top->index <= end))
		{
			ra(a);
			count_op++;
		}
	}
	else
	{
		while (!(a->top->index >= start
				&& a->top->index <= end))
		{
			rra(a);
			count_op++;
		}
	}
	return (count_op);
}

int	process_chunk(t_stack *a, t_stack *b, int start, int end)
{
	int	sent;
	int	count_op;

	sent = 0;
	count_op = 0;
	while (sent < end - start + 1)
	{
		count_op += move_chunk_to_top_a(a, start, end);
		pb(b, a);
		count_op++;
		if (b->top->index < (start + end) / 2)
		{
			rb(b);
			count_op++;
		}
		sent++;
	}
	return (count_op);
}

