/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:41:31 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/22 14:54:31 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	tiny_sort(t_stack *stack)
{
	t_element	*element;

	element = stack->head;
	if (is_highest(stack, element))
	{
		rotate_a(stack);
		if (stack->head->data > stack->head->next->data)
			swap_a(stack);
		return ;
	}
	element = stack->tail;
	if (is_highest(stack, element))
	{
		if (stack->head->data > stack->head->next->data)
			swap_a(stack);
		return ;
	}
	element = stack->head->next;
	if (is_highest(stack, element))
	{
		reverse_rotate_a(stack);
		if (stack->head->data > stack->head->next->data)
			swap_a(stack);
		return ;
	}
}
