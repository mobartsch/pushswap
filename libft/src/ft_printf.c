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

	printer = (t_prints *)malloc(sizeof(t_prints));
	if (printer == NULL)
		return (-1);
	va_start(printer->args, str);
	printer->ret_value = 0;
	init_printer(printer);
	parse_str(str, printer);
	va_end(printer->args);
	return (EXIT_SUCCESS);
}