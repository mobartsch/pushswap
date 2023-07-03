/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:35:54 by mbartsch          #+#    #+#             */
/*   Updated: 2023/07/03 14:13:09 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker_bonus.h"

static void	rev_rotate(t_stack *stack)
{
	t_element	*element;

	if (stack->head != NULL && stack->tail != NULL && stack->tail->prev != NULL)
	{
		element = stack->tail;
		stack->tail = stack->tail->prev;
		stack->tail->next = NULL;
		element->prev = NULL;
		element->next = stack->head;
		stack->head->prev = element;
		stack->head = element;
	}
}

void	reverse_rotate_a(t_stack *stack)
{
	rev_rotate(stack);
}

void	reverse_rotate_b(t_stack *stack)
{
	rev_rotate(stack);
}

void	reverse_rotate_r(t_stack *stack_a, t_stack *stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}
