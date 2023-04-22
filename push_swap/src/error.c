/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:31:17 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/21 15:15:02 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

static void	free_list(t_stack *stack)
{
	t_element	*element;
	t_element	*tmp;

	element = stack->head;
	while (element)
	{
		tmp = element;
		element = element->next;
		free(tmp);
	}
	free(stack);
}

void	error_h(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("error\n");
	free_list(stack_a);
	free_list(stack_b);
}
