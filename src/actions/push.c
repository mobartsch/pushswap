/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:55:31 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/22 15:35:28 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

static void	push(t_stack *stack_push, t_stack *stack_recive)
{
	t_element	*element;

	element = stack_push->head;
	if (stack_push->head != NULL)
	{
		stack_push->head = element->next;
		if (stack_push->head != NULL)
			stack_push->head->prev = NULL;
		else
			stack_push->tail = NULL;
	}
	element->next = stack_recive->head;
	if (stack_recive->head != NULL)
		stack_recive->head->prev = element;
	else
		stack_recive->tail = element;
	stack_recive->head = element;
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
