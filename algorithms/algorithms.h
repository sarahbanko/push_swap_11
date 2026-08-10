/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:02:15 by sbanko            #+#    #+#             */
/*   Updated: 2026/08/10 14:02:16 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "../operations/operations.h"

typedef struct s_chunk
{
	int	count;
	int	base_size;
	int	remainder;
	int	start;
	int	end;
	int	elements;
	int	current;
}	t_chunk;

double compute_disorder(t_stack *s);
void	sort_simple(t_stack *a, t_stack *b);
void	sort_complex(t_stack *a, t_stack *b);
int	sort_medium(t_stack *a, t_stack *b);
int square_root(int n);
int	process_chunk(t_stack *a, t_stack *b, int start, int end);
int push_stack_a(t_stack *b, int current_index);
void	sort_adaptive(t_stack *a, t_stack *b);

#endif
