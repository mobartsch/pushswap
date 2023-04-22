/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:43:50 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/20 15:39:31 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker_bonus.h"

int	main(int argc, char *argv[])
{
	t_ps	*stack_a;
	t_ps	*stack_b;
	int		stack_hight;

	stack_hight = 0;
	stack_a = NULL;
	stack_b = NULL;
	checker(argc, argv, &stack_a, &stack_hight);
	read_action(&stack_a, &stack_b);
	print_list(stack_a);
}
