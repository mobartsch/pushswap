/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:30:08 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/22 14:40:55 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

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
	ft_printf("ra\n");
}

void	rotate_b(t_stack *stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

void	rotate_r(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
