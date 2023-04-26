/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:14:11 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/26 13:14:14 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_bubble_sort(int *arr, int len)
{
	int	z;
	int	z2;
	int	tmp;

	z = 0;
	while (z < len)
	{
		z2 = 0;
		while (z2 < len)
		{
			if (((z2 + 1) < len) && (arr[z2] > arr[z2 + 1]))
			{
				tmp = arr[z2];
				arr[z2] = arr[z2 + 1];
				arr[z2 + 1] = tmp;
			}
			z2++;
		}
		z++;
	}
}

int	*fill_arr(t_stack *stack)
{
	int			z;
	int			*arr;
	t_element	*element;

	element = stack->head;
	z = stack_size(stack);
	arr = (int *)malloc(sizeof(int) * z);
	if (!arr)
		return (NULL);
	z = 0;
	while (element)
	{
		arr[z] = element->data;
		element = element->next;
		z++;
	}
	ft_bubble_sort(arr, z);
	return (arr);
}
