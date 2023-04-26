/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:48:52 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/22 15:37:07 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../../libft/src/includes/libft.h"
# include <limits.h>

typedef struct s_element{
	int					data;
	struct s_element	*next;
	struct s_element	*prev;
}	t_element;

typedef struct s_stack{
	struct s_element	*head;
	struct s_element	*tail;
}	t_stack;

typedef struct s_controll{
	int	size;
	int	mid_point;
	int	start_chunk;
	int	end_chunk;
	int	chunks;
	int	c_size;
	int	max;
	int	not_sorted;
}	t_control;

t_stack		*create_list(void);
int			check_input(int argc, char *argv[], t_stack *stack_a, t_stack *stack_b);
void		error_h(t_stack *stack_a, t_stack *stack_b);
void		add_list(t_stack *stack, t_element *element);
t_element	*create_element(int data);
int			*fill_arr(t_stack *stack);
void		freeer(t_stack *stack_a, t_stack *stack_b, int *arr);

void		tiny_sort(t_stack *stack);
void		five_sort(t_stack *satck_a, t_stack *stack_b);
void		big_sort(t_stack *stack_a, t_stack *stack_b, int *arr);

int			find_highest(t_stack *stack);
int			find_lowest(t_stack *stack);
int			stack_size(t_stack *stack);
void		check_up(t_stack *stack_a, t_stack *stack_b, int *arr, \
		t_control *control);
void		check_down(t_stack *stack_a, t_control *control);
void		push_highest(t_stack *stack_a, t_stack *stack_b, \
		t_control *control);

void		push_a(t_stack *stack_a, t_stack *stack_b);
void		push_b(t_stack *stack_a, t_stack *stack_b);
void		swap_a(t_stack *stack);
void		swap_b(t_stack *stack);
void		swap_s(t_stack *stack_a, t_stack *stack_b);
void		rotate_a(t_stack *stack);
void		rotate_b(t_stack *stack);
void		rotate_r(t_stack *stack_a, t_stack *stack_b);
void		reverse_rotate_a(t_stack *stack);
void		reverse_rotate_b(t_stack *stack);
void		reverse_rotate_r(t_stack *stack_a, t_stack *stack_b);

#endif
