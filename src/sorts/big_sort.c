#include "pushswap.h"

static int	init_chunks(t_control *control)
{
	if (control->size <= 30)
		return (5);
	else if (control->size <= 150)
		return (8);
	else
		return (18);
}

static t_control	*init_control(t_stack *stack)
{
	t_control	*control;

	control = (t_control *)malloc(sizeof(t_control));
	if (!control)
		return (NULL);
	control->size = stack_size(stack);
	control->chunks = init_chunks(control);
	control->mid_point = control->size / 2;
	control->c_size = control->size / control->chunks;
	control->start_chunk = control->mid_point - control->c_size;
	control->end_chunk = control->mid_point + control->c_size;
	return (control);
}

static void	big_sort_first(t_stack *stack_a, t_stack *stack_b, int *arr, \
		t_control *control)
{
	while (stack_a->head)
	{
		if (stack_size(stack_a) == 1)
			push_b(stack_a, stack_b);
		while (stack_size(stack_b) < (control->end_chunk - \
					control->start_chunk))
		{
			if (!(stack_a->head->data < arr[control->end_chunk] && \
				stack_a->head->data >= arr[control->start_chunk]))
				rotate_a(stack_a);
			else
			{
				push_b(stack_a, stack_b);
				if (stack_b->head->data < arr[control->mid_point])
					rotate_b(stack_b);
			}
		}
		control->start_chunk -= control->c_size;
		if (control->start_chunk < 0)
			control->start_chunk = 0;
		control->end_chunk += control->c_size;
		if (control->end_chunk >= control->size)
			control->end_chunk = control->size - 1;
	}
}

static void	big_sort_second(t_stack *stack_a, t_stack *stack_b, int *arr, \
		t_control *control)
{
	control->not_sorted = 0;
	control->max = stack_size(stack_b) - 1;
	while (stack_b->head)
	{
		if (stack_b->head && find_highest(stack_b) == arr[control->max])
			check_up(stack_a, stack_b, arr, control);
		else
			check_down(stack_a, control);
	}
	while (control->not_sorted != 0)
	{
		reverse_rotate_a(stack_a);
		control->not_sorted -= 1;
	}
}

void	big_sort(t_stack *stack_a, t_stack *stack_b, int *arr)
{
	t_control	*control;

	control = init_control(stack_a);
	big_sort_first(stack_a, stack_b, arr, control);
	big_sort_second(stack_a, stack_b, arr, control);
	free(control);
}
