/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:03:05 by sbanko            #+#    #+#             */
/*   Updated: 2026/08/10 14:03:06 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void    rev_rotate(t_stack *s)
{
    t_node  *last_node;

    if (!s || s->size < 2)
        return ;
    last_node = stack_pop_bottom(s);
    stack_push_top(s, last_node);
}

void    rra(t_stack *a)
{
    if (!a || a->size < 2)
        return ;
    rev_rotate(a);
    write(1, "rra\n", 4);
}

void    rrb(t_stack *b)
{
    if (!b || b->size < 2)
        return ;
    rev_rotate(b);
    write(1, "rrb\n", 4);
}

void    rrr(t_stack *a, t_stack *b)
{
    if ((!a || a->size < 2) && (!b || b->size < 2))
        return ;
    rev_rotate(a);
    rev_rotate(b);
    write(1, "rrr\n", 4);
}