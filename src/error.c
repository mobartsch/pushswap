/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:31:17 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/26 13:35:09 by mbartsch         ###   ########.fr       */
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

void	freeer(t_stack *stack_a, t_stack *stack_b, int *arr)
{
	free_list(stack_a);
	free_list(stack_b);
	free(arr);
}

void	free_split(char **args)
{
	int	z;

	z = 0;
	while (args[z])
	{
		free(args[z]);
		z++;
	}
	free(args);
}

void	error_h(t_stack *stack_a, t_stack *stack_b)
{
	write(2, "error\n", 6);
	free_list(stack_a);
	free_list(stack_b);
	exit (0);
}
