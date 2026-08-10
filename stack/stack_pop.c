#include "stack.h"

t_node	*stack_pop_top(t_stack *s)
{
    t_node  *last_node;
    t_node  *new_top;
    t_node  *pop_top;

    if (!s || !s->top)
        return (NULL);
    pop_top = s->top; 
    last_node = s->top->prev; 
    new_top = s->top->next;
    if (s->size > 1) 
    {
        s->top = new_top;
        new_top->prev = last_node;
        last_node->next = new_top;
        s->size--;
    }
    else if (s->size == 1) 
    {
        s->top = NULL;
        s->size--;
    }
    pop_top->prev = pop_top; 
    pop_top->next = pop_top; 
    return (pop_top);
}

t_node	*stack_pop_bottom(t_stack *s)
{
    t_node  *pop_bottom;
    t_node  *last_node;

    if (!s || !s->top)
        return (NULL);
    pop_bottom = s->top->prev; 
    if (s->size > 1)
    {
        s->top->prev = pop_bottom->prev; 
        last_node = pop_bottom->prev; 
        last_node->next = s->top; 
        s->size--;
    }
    else if (s->size == 1)
    {
        s->top = NULL;
        s->size--;
    }
    pop_bottom->prev = NULL; 
    pop_bottom->next = NULL;
    return (pop_bottom);
}

