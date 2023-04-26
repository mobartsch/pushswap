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
