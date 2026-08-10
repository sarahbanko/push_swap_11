/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:02:58 by sbanko            #+#    #+#             */
/*   Updated: 2026/08/10 14:02:59 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void    pa(t_stack *a, t_stack *b)
{
    if (!a || !b || b->size == 0)
        return ;
    stack_push_top(a, stack_pop_top(b));
    write(1, "pa\n", 3);
}

void    pb(t_stack *b, t_stack *a)
{
    if (!a || !b || a->size == 0)
        return ;
    stack_push_top(b, stack_pop_top(a));
    write(1, "pb\n", 3);
}
