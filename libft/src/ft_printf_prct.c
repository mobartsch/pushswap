#include "libft.h"

void	ft_printf_prct(t_prints *printer)
{
	printer->ret_value += write(1, "%", 1);
}
