#ifndef CHECKER_H
# define CHECKER_H

#include <stdlib.h>
#include "../../libft/src/includes/libft.h"

typedef struct s_element{
	int			data;
	struct s_element	*next;
	struct s_element	*prev;
}	t_element;

typedef struct s_stack{
	struct s_element	*head;
	struct s_element	*tail;
}	t_stack;

int		check_input(int argc, char *argv[], t_stack *stack_a, t_stack *stack_b);
int		check_sorted(t_stack *stack_a);
int		stack_active(t_stack *stack);

t_stack	*create_list(void);
void	error_h(t_stack *stack_a, t_stack *stack_b);

void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_s(t_stack *stack_a, t_stack *stack_b);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_r(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_r(t_stack *stack_a, t_stack *stack_b);
#endif	
