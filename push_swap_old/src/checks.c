/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:58:46 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/19 16:52:39 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

int	check_int(char *arg)
{
	int	z;

	z = 0;
	while (arg[z])
	{
		if (!((arg[z] >= '0' && arg[z] <= '9') || arg[z] == '-'))
			error_h();
		z++;
	}
	z = ft_atoi(arg);
	if (z > INT_MAX || z < INT_MIN)
		error_h();
	return (z);
}

void	check_dup(int data, t_ps *stack_a)
{
	t_ps	*count;

	if (stack_a)
	{
		count = stack_a;
		while (count)
		{
			if (count->data == data)
				error_h();
			count = count->before;
		}
	}
}

int	check_sorted(t_ps **stack)
{
	t_ps	*tmp;

	tmp = (*stack);
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_ps	**get_head(t_ps **stack_a)
{
	while ((*stack_a)->before)
		(*stack_a) = (*stack_a)->before;
	return (stack_a);
}

t_ps	**checker(int argc, char *argv[], t_ps **stack_a, int *sh)
{
	int	tmp;
	int	index;

	index = 0;
	if (argc < 2)
		exit(1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv++;
	while (*argv)
	{
		tmp = check_int(*argv);
		check_dup(tmp, *stack_a);
		feed_a(stack_a, tmp, index);
		index++;
		sh++;
		argv++;
	}
	get_head(stack_a);
	return (stack_a);
}
