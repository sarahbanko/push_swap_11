/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarahbanko <sarahbanko@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:03:14 by sbanko            #+#    #+#             */
/*   Updated: 2026/08/11 16:36:07 by sarahbanko       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void    rotate(t_stack *s)
{
    t_node  *first_node;

    if (!s || s->size < 2)
        return ;
    first_node = stack_pop_top(s);
    stack_push_bottom(s, first_node);
}

int    ra(t_stack *a)
{
    int count_ra;

    count_ra = 1;
    if (!a || a->size < 2) 
        return (0);
    rotate(a);
    write(1, "ra\n", 3);
    return (count_ra);
}

int    rb(t_stack *b)
{
    int count_rb;

    count_rb = 1;
    if (!b || b->size < 2)
        return (0);
    rotate(b);
    write(1, "rb\n", 3);
    return (count_rb);
}

int    rr(t_stack *a, t_stack *b)
{
    int count_rr;

    count_rr = 1;
    if ((!a || a->size < 2) && (!b || b->size < 2))
        return (0);
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
    return (count_rr);
}