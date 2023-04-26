#include "checker.h"

static void	free_list(t_stack *stack)
{
	t_element	*element;
	t_element	*tmp;

	element = stack->head;
	while (element)
	{
		tmp = element;
		element = element->next;
		free(tmp);
	}
	free(stack);
}

void	error_h(t_stack *stack_a, t_stack *stack_b)
{
	free_list(stack_a);
	free_list(stack_b);
	ft_printf("error\n");
	exit (0);
}

static int	check_instruction(char *check, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(check, "ra\n", 3) == 0)
		rotate_a(stack_a);
	else if (ft_strncmp(check, "rb\n", 3) == 0)
		rotate_b(stack_b);
	else if (ft_strncmp(check, "rr\n", 3) == 0)
		rotate_r(stack_a, stack_b);
	else if (ft_strncmp(check, "sa\n", 3) == 0)
		swap_a(stack_a);
	else if (ft_strncmp(check, "sb\n", 3) == 0)
		swap_b(stack_b);
	else if (ft_strncmp(check, "ss\n", 3) == 0)
		swap_s(stack_a, stack_b);
	else if (ft_strncmp(check, "pa\n", 3) == 0)
		push_a(stack_a, stack_b);
	else if (ft_strncmp(check, "pb\n", 3) == 0)
		push_b(stack_a, stack_b);
	else if (ft_strncmp(check, "rra\n", 4) == 0)
		reverse_rotate_a(stack_a);
	else if (ft_strncmp(check, "rrb\n", 4) == 0)
		reverse_rotate_b(stack_b);
	else if (ft_strncmp(check, "rrr\n", 4) == 0)
		reverse_rotate_r(stack_a, stack_b);
	else
		error_h(stack_a, stack_b);
	return (1);
}

static int	check_sort(t_stack *stack_a, t_stack *stack_b)
{
	char	*inst;

	inst = get_next_line(0);
	while (inst)
	{
		if (!check_instruction(inst, stack_a, stack_b))
			error_h(stack_a, stack_b);
		inst = get_next_line(0);
	}
	return (check_sorted(stack_a));	
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		z;

	stack_a = create_list();
	stack_b = create_list();
	z = check_input(argc, argv, stack_a, stack_b);
	if (z == 2)
	{
		ft_printf("OK\n");
		return (0);
	}
	else if (!z)
	{
		error_h(stack_a, stack_b);
		return (0);
	}
	z = check_sort(stack_a, stack_b);
	free_list(stack_a);
	free_list(stack_b);
	if (z == 2)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
