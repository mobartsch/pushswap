/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:14:12 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/18 14:25:05 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	init_printer(t_prints *printer)
{
	printer->hash = 0;
	printer->space = 0;
	printer->plus = 0;
	printer->minus = 0;
	printer->zero = 0;
	printer->dot = 0;
	printer->width = 0;
	printer->precision = 0;
	printer->pos = 0;
	printer->null = 0;
	printer->conv = '\0';
}

int	ft_printf(const char *str, ...)
{
	t_prints	*printer;
	int			ret;

	printer = (t_prints *)malloc(sizeof(t_prints));
	if (printer == NULL || !str)
		return (-1);
	va_start(printer->args, str);
	printer->ret_value = 0;
	init_printer(printer);
	parse_str(str, printer);
	va_end(printer->args);
	ret = printer->ret_value;
	free(printer);
	return (ret);
}
