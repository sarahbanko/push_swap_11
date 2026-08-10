/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:53:21 by sbanko            #+#    #+#             */
/*   Updated: 2026/08/10 13:50:35 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <limits.h>

int	match_flag(const char *user_flag, const char *real_flag)
{
	int	i;

	i = 0;
	while (real_flag[i])
	{
		if (user_flag[i] != real_flag[i])
			return (0);
		i++;
	}
	return (user_flag[i] == '\0');
}

static int	parse_digits(const char *str, int *i, long *result, int sign)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*result = *result * 10 + (str[*i] - '0');
		if (*result * sign > INT_MAX || *result * sign < INT_MIN)
			return (0);
		(*i)++;
	}
	return (1);
}

int	is_valid_int(const char *str, int *value)
{
	long	res;
	int	sign;
	int	i;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	if (!parse_digits(str, &i, &res, sign))
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 12))
		i++;
	if (str[i] != '\0')
		return (0);
	*value = (int)(res * sign);
	return (1);
}

int	has_duplicate(t_stack *a, int value)
{
	t_node	*current;
	int	i;

	if (!a || a->size == 0)
		return (0);
	current = a->top;
	i = 0;
	while (i < a->size)
	{
		if (current->content == value)
			return (1);
		current = current->next;
		i++;
	}
	return (0);

}











































