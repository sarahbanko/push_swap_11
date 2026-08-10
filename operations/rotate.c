/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:03:14 by sbanko            #+#    #+#             */
/*   Updated: 2026/08/10 14:03:15 by sbanko           ###   ########.fr       */
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

void    ra(t_stack *a)
{
    if (!a || a->size < 2) 
        return ;
    rotate(a);
    write(1, "ra\n", 3);
}

void    rb(t_stack *b)
{
    if (!b || b->size < 2)
        return ;
    rotate(b);
    write(1, "rb\n", 3);
}

void    rr(t_stack *a, t_stack *b)
{
    if ((!a || a->size < 2) && (!b || b->size < 2))
        return ;
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}