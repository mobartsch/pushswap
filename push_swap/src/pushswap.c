/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:02:20 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/22 16:06:50 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_element	*print;

	print = stack->head;
	while (print)
	{
		printf("%d\n", print->data);
		print = print->next;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		z;

	if (argc < 2)
		return (0);
	stack_a = create_list();
	stack_b = create_list();
	z = check_input(argc, argv, stack_a);
	if (z == 2)
		return (0);
	else if (!z)
	{
		error_h(stack_a, stack_b);
		return (0);
	}
	five_sort(stack_a, stack_b);
	//print_stack(stack_a);
}
