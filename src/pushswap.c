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
	ft_printf("\n");
	while (print)
	{
		printf("%d\n", print->data);
		print = print->next;
	}
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int *arr)
{
	int	stack_hight;

	stack_hight = stack_size(stack_a);
	if (stack_hight == 2)
	{
		if (stack_a->head->data > stack_a->head->next->data)
			swap_a(stack_a);
	}
	else if (stack_hight == 3)
		tiny_sort(stack_a);
	else if (stack_hight <= 5)
		five_sort(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b, arr);
	freeer(stack_a, stack_b, arr);
}	

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			z;
	int			*arr;

	if (argc < 2)
		return (0);
	stack_a = create_list();
	stack_b = create_list();
	z = check_input(argc, argv, stack_a, stack_b);
	if (z == 2)
		return (0);
	else if (z == 0)
	{
		error_h(stack_a, stack_b);
		return (0);
	}
	arr = fill_arr(stack_a);
	sort_stack(stack_a, stack_b, arr);
}
