/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:54:05 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/22 15:33:08 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

int	find_highest(t_stack *stack)
{
	t_element	*tmp;
	int			highest;

	tmp = stack->head;
	highest = tmp->data;
	while (tmp)
	{
		if (tmp->data > highest)
			highest = tmp->data;
		tmp = tmp->next;
	}
	return (highest);
}

int	find_lowest(t_stack *stack)
{
	t_element	*tmp;
	int			lowest;

	tmp = stack->head;
	lowest = tmp->data;
	while (tmp)
	{
		if (tmp->data < lowest)
			lowest = tmp->data;
		tmp = tmp->next;
	}
	return (lowest);
}

int	stack_size(t_stack *stack)
{
	t_element	*element;
	int			size;

	size = 0;
	element = stack->head;
	while (element)
	{
		size++;
		element = element->next;
	}
	return (size);
}

void	check_up(t_stack *stack_a, t_stack *stack_b, int *arr, \
		t_control *control)
{
	if (stack_b->head->data == arr[control->max])
	{
		push_a(stack_a, stack_b);
		control->max -= 1;
		if (stack_a->head->next && (stack_a->head->data > \
					stack_a->head->next->data))
		{
			swap_a(stack_a);
			control->max -= 1;
		}
	}
	else if (stack_b->head->data == arr[control->max - 1])
		push_a(stack_a, stack_b);
	else
		push_highest(stack_a, stack_b, control);
}

void	check_down(t_stack *stack_a, t_control *control)
{
	if (control->not_sorted > 0)
	{
		reverse_rotate_a(stack_a);
		control->not_sorted -= 1;
		control->max -= 1;
	}
}
