#include "checker.h"

int	stack_active(t_stack *stack)
{
	if (!stack->head)
		return (0);
	return (1);
}
