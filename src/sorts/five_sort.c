/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:56:49 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/22 16:15:54 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

static int	find_second_lowest(t_stack *stack_a)
{
	int			lowest;
	int			sec_lowest;
	t_element	*element;

	lowest = find_lowest(stack_a);
	element = stack_a->head;
	if (element->data != lowest)
		sec_lowest = element->data;
	else
		sec_lowest = element->next->data;
	while (element)
	{
		if (element->data < sec_lowest && element->data != lowest)
			sec_lowest = element->data;
		element = element->next;
	}
	return (sec_lowest);
}

void	five_sort(t_stack *stack_a, t_stack *stack_b)
{
	int			lowest;
	int			sec_lowest;
	t_element	*element;

	lowest = find_lowest(stack_a);
	element = stack_a->head;
	if (stack_size(stack_a) == 5)
		sec_lowest = find_second_lowest(stack_a);
	else
		sec_lowest = lowest;
	while (stack_size(stack_a) > 3)
	{
		element = stack_a->head;
		if (element->data == lowest || element->data == sec_lowest)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	tiny_sort(stack_a);
	if (stack_b->head->next && (stack_b->head->data < \
				stack_b->head->next->data))
		swap_b(stack_b);
	while (stack_b->head)
		push_a(stack_a, stack_b);
}
