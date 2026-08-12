/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PersonA <persona@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 00:00:00 by PersonA           #+#    #+#             */
/*   Updated: 2026/07/19 00:00:00 by PersonA          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	index_stack(t_stack *s)
{
	int		smaller;
	int		count;
	int		count_current;
	t_node	*current;
	t_node	*next;

	if (!s || !s->top)
		return ;
	count_current = 0;
	current = s->top;
	while (++count_current <= s->size)
	{
		smaller = 0;
		count = 0;
		next = current->next;
		while (++count < s->size)
		{
			if (next->content < current->content)
				smaller++;
			next = next->next;
		}
		current->index = smaller;
		current = current->next;
	}
}

int	*stack_extract_values(t_stack *a)
{
	int		*arr;
	t_node	*curr;
	int		i;

	arr = (int *)malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	curr = a->top;
	i = 0;
	while (i < a->size)
	{
		arr[i] = curr->content;
		curr = curr->next;
		i++;
	}
	return (arr);
}

void	stack_sort_array(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	stack_min_pos(t_stack *s)
{
	t_node	*curr;
	int		min_idx;
	int		min_pos;
	int		i;

	curr = s->top;
	min_idx = curr->index;
	min_pos = 0;
	i = 0;
	while (i < s->size)
	{
		if (curr->index < min_idx)
		{
			min_idx = curr->index;
			min_pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (min_pos);
}
