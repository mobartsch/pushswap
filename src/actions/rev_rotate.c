/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:35:54 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/22 14:53:39 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

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
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack *stack)
{
	rev_rotate(stack);
	ft_printf("rrb\n");
}

void	reverse_rotate_r(t_stack *stack_a, t_stack *stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_printf("rrr\n");
}
