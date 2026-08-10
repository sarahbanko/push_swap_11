/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:26:15 by sarahbanko        #+#    #+#             */
/*   Updated: 2026/08/10 12:52:25 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

double compute_disorder(t_stack *s)
{
    int mistakes;
    int total_pairs;
    t_node  *current;
    t_node  *next;

    if (!s || s->size < 2)
        return (0);
    mistakes = 0;
    total_pairs = 0;
    current = s->top;
    while (current->next != s->top)
    {
        next = current->next;
        while (next != s->top)
        {
            total_pairs++;
            if (current->content > next->content)
                mistakes++;
            next = next->next;
        }
        current = current->next;
    }
    return ((double)mistakes/total_pairs);
}
