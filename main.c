/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PersonA <persona@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 00:00:00 by PersonA           #+#    #+#             */
/*   Updated: 2026/07/19 00:00:00 by PersonA          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	is_sorted(t_stack *a)
{
	t_node	*curr;
	int		i;

	if (a->size <= 1)
		return (1);
	curr = a->top;
	i = 0;
	while (i < a->size - 1)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
		i++;
	}
	return (1);
}

static void	free_args(char **args, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
		free(args[i++]);
	free(args);
}

static void	bench_report(t_strategy strat, double disorder)
{
	(void)strat;
	(void)disorder;
}

static void	sort_stack(t_stack *a, t_stack *b, t_strategy strat, int bench)
{
	double	disorder;

	if (is_sorted(a))
		return ;
	index_stack(a);
	disorder = 0.0;
	if (bench)
		disorder = compute_disorder(a);
	if (strat == SIMPLE)
		sort_simple(a, b);
	else if (strat == MEDIUM)
		sort_medium(a, b);
	else if (strat == COMPLEX)
		sort_complex(a, b);
	else
		sort_adaptive(a, b);
	if (bench)
		bench_report(strat, disorder);
}

int	main(int argc, char **argv)
{
	t_strategy	strat;
	int			bench;
	t_stack		*a;
	t_stack		*b;
	char		**args;

	args = build_args(argc, argv, &argc);
	if (!args)
		return (1);
	a = parsing(argc, args, &strat, &bench);
	if (!a)
	{
		free_args(args, argc);
		return (1);
	}
	free_args(args, argc);
	if (a->size == 0)
		return (stack_free(a), 0);
	b = stack_init();
	if (!b)
		return (stack_free(a), 1);
	sort_stack(a, b, MEDIUM, bench); // DEFAULT VALUE IS strat
	stack_free(a);
	stack_free(b);
	return (0);
}
