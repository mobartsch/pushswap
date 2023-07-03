/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:38:57 by mbartsch          #+#    #+#             */
/*   Updated: 2023/07/03 14:39:38 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker_bonus.h"

int	stack_active(t_stack *stack)
{
	if (!stack && !stack->head)
		return (0);
	return (1);
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
