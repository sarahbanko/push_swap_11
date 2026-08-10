/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 13:00:12 by sbanko            #+#    #+#             */
/*   Updated: 2026/08/10 14:11:49 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;
	
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack -> top = NULL;
	stack -> size = 0;
	return (stack);
}

void	stack_free(t_stack *s)
{
	t_node	*temp;
	t_node	*current_node; 
	t_node	*last_node;
	
	if (!s)
		return ;
	if (!s->top) 
	{
		free(s);
		return ;
	}
	current_node = s->top; 
	last_node = s->top->prev; 
	while (current_node != last_node) 
	{
		temp = current_node->next;
		free(current_node);
		current_node = temp;
	}
	free(current_node); 
	
	free(s);
}