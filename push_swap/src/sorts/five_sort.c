/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:56:49 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/22 16:15:54 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	five_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*element;

	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	tiny_sort(stack_a);
	
}
