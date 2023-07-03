/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:42:45 by mbartsch          #+#    #+#             */
/*   Updated: 2023/07/03 14:13:26 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker_bonus.h"

t_stack	*create_list(void)
{
	t_stack	*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	return (list);
}

t_element	*create_element(int data)
{
	t_element	*new;

	new = (t_element *)malloc(sizeof(t_element));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->next = NULL;
	new->data = data;
	return (new);
}

void	add_list(t_stack *stack, t_element *element)
{
	t_element	*cnt;

	if (stack->head == NULL)
	{
		stack->head = element;
		stack->tail = element;
	}
	else
	{
		cnt = stack->head;
		while (cnt->next)
			cnt = cnt->next;
		cnt->next = element;
		element->prev = cnt;
		stack->tail = element;
	}
}
