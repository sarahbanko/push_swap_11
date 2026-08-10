/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:54:28 by sbanko            #+#    #+#             */
/*   Updated: 2026/08/10 14:08:42 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_node {
	int	content;
	int index;
	struct s_node *next;
	struct s_node *prev;
} t_node;

typedef struct s_stack {
	t_node *top;
	int size;
} t_stack;

t_node	*new_node(int value);
t_node	*stack_pop_top(t_stack *s);
t_node	*stack_pop_bottom(t_stack *s);
t_stack	*stack_init(void);
void	stack_push_top(t_stack *s, t_node *node);
void	stack_push_bottom(t_stack *s, t_node *node);
void	stack_free(t_stack *s);
void	index_stack(t_stack *s);
int		stack_min_pos(t_stack *s);
int		*stack_extract_values(t_stack *a);
void	stack_sort_array(int *arr, int n);

#endif 

