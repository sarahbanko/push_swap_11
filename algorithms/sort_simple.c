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

static void sort_three(t_stack *a)
{
    int top = a->top->content;
    int mid = a->top->next->content;
    int bot = a->top->next->next->content;

    if (top > mid && mid < bot && top < bot)
        sa(a);
    else if (top > mid && mid > bot)
        { 
			sa(a);
			rra(a); 
		}
    else if (top > mid && mid < bot && top > bot)
        ra(a);
    else if (top < mid && mid > bot && top < bot)
        { 
			sa(a);
			ra(a); 
		}
    else if (top < mid && mid > bot && top > bot)
        rra(a);
}

void sort_simple(t_stack *a, t_stack *b)
{
    int min_pos;

    if (a->size <= 1)
        return ;
    if (a->size == 2 && a->top->content > a->top->next->content)
        sa(a);
    else if (a->size == 3)
        sort_three(a);
    else if (a->size <= 5)
    {
        while (a->size > 3)
        {
            min_pos = stack_min_pos(a);
            if (min_pos <= a->size / 2)
                while (min_pos--)
                    ra(a);
            else
                while (min_pos++ < a->size)
                    rra(a);
            pb(b, a);
        }
        sort_three(a);
        while (b->size > 0)
            pa(a, b);
    }
}
