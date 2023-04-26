/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:23:15 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/22 14:42:23 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->head != NULL && stack->head->next != NULL)
	{
		tmp = stack->head->data;
		stack->head->data = stack->head->next->data;
		stack->head->next->data = tmp;
	}
}

void	swap_a(t_stack *stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	swap_b(t_stack *stack)
{
	swap(stack);
	ft_printf("sb\n");
}

void	swap_s(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
