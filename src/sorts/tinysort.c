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
	int		highest;

	highest = find_highest(stack);
	if (stack->head->data == highest)
	{
		rotate_a(stack);
		if (stack->head->data > stack->head->next->data)
			swap_a(stack);
		return ;
	}
	if (stack->tail->data == highest)
	{
		if (stack->head->data > stack->head->next->data)
			swap_a(stack);
		return ;
	}
	if (stack->head->next->data == highest)
	{
		reverse_rotate_a(stack);
		if (stack->head->data > stack->head->next->data)
			swap_a(stack);
		return ;
	}
}
