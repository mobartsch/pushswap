/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:08:14 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/21 16:03:04 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

static int	check_int(int nbr)
{
	if (nbr >= INT_MIN && nbr <= INT_MAX)
		return (1);
	else
		return (0);
}

static int	check_dup(int nbr, t_stack *stack)
{
	t_element	*element;

	element = stack->head;
	while (element)
	{
		if (element->data == nbr)
			return (0);
		element = element->next;
	}
	return (1);
}

static int	check_valid(char *arg)
{
	while (*arg)
	{
		if (!(*arg >= '0' && *arg <= '9') && !(*arg == '-'))
			return (0);
		arg++;
	}
	return (1);
}

static int	check_sorted(t_stack *stack)
{
	t_element	*element;

	element = stack->head;
	while (element && element->next)
	{
		if (element->data > element->next->data)
			return (1);
		element = element->next;
	}
	return (2);
}

int	check_input(int argc, char *argv[], t_stack *stack)
{
	int		z;
	int		nbr;

	z = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (0);
		z = 0;
	}
	while (argv[z])
	{
		if (!check_valid(argv[z]))
			return (0);
		nbr = ft_atoi(argv[z]);
		if (check_int(nbr) && check_dup(nbr, stack))
			add_list(stack, create_element((int)nbr));
		else
			return (0);
		z++;
	}
	return (check_sorted(stack));
}
