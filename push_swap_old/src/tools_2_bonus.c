/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:47:09 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/20 13:42:15 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	error_h(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ps_rev_rotate(t_ps **stack)
{
	t_ps	*tmp;
	t_ps	*count;

	if ((*stack) && (*stack)->next)
	{
		tmp = (*stack);
		count = (*stack);
		while ((*stack)->next)
			(*stack) = (*stack)->next;
		(*stack)->before->next = NULL;
		(*stack)->before = NULL;
		(*stack)->next = tmp;
		tmp->before = (*stack);
	}
}

void	ps_rev_rotate_both(t_ps **stack_a, t_ps **stack_b)
{
	ps_rev_rotate(stack_a);
	ps_rev_rotate(stack_b);
}

t_ps	*create_node(t_ps *node, int data, int index)
{
	node = (t_ps *)malloc(sizeof(t_ps));
	if (node == NULL)
		error_h();
	node->next = NULL;
	node->before = NULL;
	node->data = data;
	node->index = index;
	return (node);
}

t_ps	**feed_a(t_ps **stack_a, int data, int index)
{
	t_ps	*node;

	node = NULL;
	if (*stack_a == NULL)
	{
		*stack_a = create_node(*stack_a, data, index);
	}
	else
	{
		node = create_node(node, data, index);
		(*stack_a)->next = node;
		node->before = (*stack_a);
		(*stack_a) = node;
	}
	return (stack_a);
}
