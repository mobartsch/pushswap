/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:40:24 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/20 12:27:46 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ps_switch(t_ps **stack)
{
	t_ps	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	(*stack)->before = tmp;
	tmp->next = (*stack);
	tmp->before = NULL;
	(*stack) = tmp;
}

void	ps_switch_both(t_ps **stack_a, t_ps **stack_b)
{
	ps_switch(stack_a);
	ps_switch(stack_b);
}

void	ps_push(t_ps **stack_r, t_ps **stack_p)
{
	t_ps	*tmp;

	if (*stack_p == NULL)
		;
	else if ((*stack_r) == NULL)
	{
		init_stack(stack_r);
		(*stack_r)->data = (*stack_p)->data;
		(*stack_r)->before = NULL;
		(*stack_r)->next = NULL;
		(*stack_p) = (*stack_p)->next;
		(*stack_p)->before = NULL;
	}
	else
	{
		tmp = (*stack_p);
		(*stack_p) = (*stack_p)->next;
		if (*stack_p)
			(*stack_p)->before = NULL;
		(*stack_r)->before = tmp;
		tmp->next = (*stack_r);
		(*stack_r) = tmp;
	}
}

void	ps_rotate(t_ps **stack)
{
	t_ps	*tmp;
	t_ps	*count;

	if ((*stack) && (*stack)->next)
	{
		count = (*stack);
		tmp = (*stack);
		(*stack) = (*stack)->next;
		while (count->next)
			count = count->next;
		count->next = tmp;
		(*stack)->before = NULL;
		tmp->before = count;
		tmp->next = NULL;
	}
}

void	ps_rotate_both(t_ps **stack_a, t_ps **stack_b)
{
	ps_rotate(stack_a);
	ps_rotate(stack_b);
}
