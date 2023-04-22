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

int	is_highest(t_stack *stack, t_element *element)
{
	t_element	*tmp;

	tmp = stack->head;
	while (tmp)
	{
		if (tmp->data > element->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_lowest(t_stack *stack, t_element *element)
{
	t_element	*tmp;

	tmp = stack->head;
	while (tmp)
	{
		if (tmp->data < element->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
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
