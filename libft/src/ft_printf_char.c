#include "libft.h"

static void	char_width(t_prints *printer)
{
	while (--printer->width > 0)
		printer->ret_value += write(1, " ", 1);
}

static void	char_print(char c, t_prints *printer)
{
	if (printer->minus)
	{
		printer->ret_value += write(1, &c, 1);
		char_width(printer);
	}
	else
	{
		char_width(printer);
		printer->ret_value += write(1, &c, 1);
	}
}

void	ft_printf_char(t_prints *printer)
{
	char	c;

	c = (char) va_arg(printer->args, int);
	char_print(c, printer);
}
