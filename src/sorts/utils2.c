#include "pushswap.h"

t_element	*list_last_item(t_stack *stack)
{
	t_element	*element;

	element = stack->head;
	if (!element)
		return (NULL);
	while (element->next)
		element = element->next;
	return (element);
}

int	find_highest_index(t_stack *stack, int highest)
{
	t_element	*element;
	int			z;

	element = stack->head;
	z = 0;
	while (element)
	{
		if (highest == element->data)
			return (z);
		z++;
		element = element->next;
	}
	return (-1);
}

void	push_highest(t_stack *stack_a, t_stack *stack_b, t_control *control)
{
	if (control->not_sorted == 0 || (stack_b->head->data > \
				list_last_item(stack_a)->data))
	{
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
		control->not_sorted += 1;
	}
	else
	{
		if (find_highest_index(stack_b, find_highest(stack_b)) < \
				(stack_size(stack_b) / 2))
			rotate_b(stack_b);
		else
			reverse_rotate_b(stack_b);
	}
}
