/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:37:57 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/20 13:56:37 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker_bonus.h"
#include <stdio.h>
void	print_list(t_ps *stack)
{
	t_ps	*count;

	if (stack)
	{
		count = stack;
		while (count)
		{
			printf("index: %d, value: %d\n", count->index, count->data);
			count = count->next;
		}
	}
}

void	init_stack(t_ps **stack)
{
	(*stack) = (t_ps *)malloc(sizeof(t_ps));
	if ((*stack) == NULL)
		error_h();
	(*stack)->data = '\0';
}

int	stack_sorted(t_ps *stack)
{
	t_ps	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
