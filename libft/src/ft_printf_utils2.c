/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:14:37 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/18 14:43:44 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	swap_buff(char *buffer, int len)
{
	int	z;
	int	sp;

	if (buffer[0] == '-')
		z = 1;
	else
		z = 0;
	while (len > z)
	{
		len--;
		sp = buffer[z];
		buffer[z] = buffer[len];
		buffer[len] = sp;
		z++;
	}
}

size_t	ft_strlen(const char *buffer)
{
	int	z;

	z = 0;
	while (buffer[z])
		z++;
	return (z);
}
