/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarahbanko <sarahbanko@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:02:44 by sbanko            #+#    #+#             */
/*   Updated: 2026/08/11 16:34:43 by sarahbanko       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

#include "../stack/stack.h"

int    swap(t_stack *s);
int    sa(t_stack *a);
int    sb(t_stack *b);
int    ss(t_stack *a, t_stack *b);
int    pa(t_stack *a, t_stack *b);
int    pb(t_stack *b, t_stack *a);
void    rotate(t_stack *s);
int    ra(t_stack *a);
int    rb(t_stack *b);
int    rr(t_stack *a, t_stack *b);
void    rev_rotate(t_stack *s);
int    rra(t_stack *a);
int    rrb(t_stack *b);
int    rrr(t_stack *a, t_stack *b);

#endif