/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:30:08 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/26 14:26:54 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

static void	rotate(t_stack *stack)
{
	t_element	*element;

	if (stack->head != NULL && stack->head->next != NULL)
	{
		element = stack->head;
		stack->head = stack->head->next;
		stack->head->prev = NULL;
		stack->tail->next = element;
		element->prev = stack->tail;
		element->next = NULL;
		stack->tail = element;
	}
}

void	rotate_a(t_stack *stack)
{
	rotate(stack);
}

void	rotate_b(t_stack *stack)
{
	rotate(stack);
}

void	rotate_r(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
