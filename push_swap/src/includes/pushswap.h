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

# include "../../libft/libft.h"
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

t_stack		*create_list(void);
int			check_input(int argc, char *argv[], t_stack *list);
void		error_h(t_stack *stack_a, t_stack *stack_b);
void		add_list(t_stack *stack, t_element *element);
t_element	*create_element(int data);
void		sort_stack(t_stack *satck_a, t_stack *stack_b);
void		sort_medium(t_stack *stack_a, t_stack *stack_b);
void		sort_large(t_stack *stack_a, t_stack *stack_b);
int			get_chunk_size(int size);
int			get_max(t_stack *satck, int chunk_size);
int			get_min(t_stack *stack);

void		tiny_sort(t_stack *stack);
void		five_sort(t_stack *satck_a, t_stack *stack_b);

int			is_highest(t_stack *stack, t_element *element);
int			is_lowest(t_stack *stack, t_element *element);
int			stack_size(t_stack *stack);

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
