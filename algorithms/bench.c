/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 13:09:16 by sarahbanko        #+#    #+#             */
/*   Updated: 2026/08/12 18:39:32 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

void	bench_disorder(double disorder)
{
	int	integer_part;
	int	decimal_part;
	int	rounded_value;

	rounded_value = (int)((disorder * 100) * 100 + 0.5);
	integer_part = rounded_value / 100;
	decimal_part = rounded_value % 100;
	write(2, "[bench] disorder: ", 18);
	ft_putnbr_fd(integer_part, 2);
	write(2, ".", 1);
	if (decimal_part < 10)
		write(2, "0", 1);
	ft_putnbr_fd(decimal_part, 2);
	write(2, "%", 1);
	write(2, "\n", 1);
}

static void	bench_print_strategy(t_strategy strat, double disorder, int s_size)
{
	write(2, "[bench] strategy: ", 18);
	if (strat == SIMPLE)
		write(2, "Simple / O(n^2)", 15);
	else if (strat == MEDIUM)
		write(2, "Medium / O(n*sqrt(n))", 21);
	else if (strat == COMPLEX)
		write(2, "Complex / O(n log n)", 20);
	else if (strat == ADAPTIVE && s_size > 5)
	{
		write(2, "Adaptive / ", 11); // corrigir
		
		if (disorder < 0.2)
			write(2, "O(n^2)", 6);
		else if (disorder < 0.5)
			write(2, "O(n*sqrt(n))", 12);
		else
			write(2, "O(n log n)", 10);
	}
	if (s_size <= 5) // revisar pq esta errado
		write(2, "Forced / O(n^2)", 15);
	write(2, "\n", 1);
}

static void	bench_print_op(int n, char *name)
{
		write(2, name, ft_strlen(name));
		write(2, " ", 1);
		ft_putnbr_fd(n, 2);
}

static void	bench_print_ops(t_opcount *c)
{
	write(2, "[bench] total_ops: ", 19);
	ft_putnbr_fd(c->sa + c->sb + c->ss + c->pa + c->pb
		+ c->ra + c->rb + c->rr + c->rra + c->rrb + c->rrr, 2);
	write(2, "\n", 1);
	bench_print_op(c->sa, "[bench] sa: ");
	bench_print_op(c->sb, " sb: ");
	bench_print_op(c->ss, " ss: ");
	bench_print_op(c->pa, " pa: ");
	bench_print_op(c->pb, " pb: ");
	write(2, "\n", 1);
	bench_print_op(c->ra, "[bench] ra: ");
	bench_print_op(c->rb, " rb: ");
	bench_print_op(c->rr, " rr: ");
	bench_print_op(c->rra, " rra: ");
	bench_print_op(c->rrb, " rrb: ");
	bench_print_op(c->rrr, " rrr: ");
	write(2, "\n", 1);
}

void	bench_strategy(t_strategy strat, double disorder, t_opcount *c, int s_size)
{
	bench_print_strategy(strat, disorder, s_size);
	bench_print_ops(c);
}
