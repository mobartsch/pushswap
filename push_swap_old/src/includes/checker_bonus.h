/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:31:43 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/20 15:39:46 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <limits.h>
# include "../../libft/libft.h"

typedef struct s_ps{
	struct s_ps	*next;
	struct s_ps	*before;
	int			data;
	int			index;
}	t_ps;

void	error_h(void);
void	init_stack(t_ps **stack);
t_ps	**checker(int argc, char *argv[], t_ps **stack_a, int *sh);
int		check_sorted(t_ps **stack);
t_ps	**feed_a(t_ps **stack_a, int data, int index);
void	read_action(t_ps **stack_a, t_ps **stack_b);
void	print_list(t_ps *stack);
void	ps_switch(t_ps **stack);
void	ps_switch_both(t_ps **stack_a, t_ps **stack_b);
void	ps_swap(t_ps **stack);
void	ps_push(t_ps **stack_r, t_ps **stack_p);
void	ps_rotate(t_ps **stack);
void	ps_rotate_both(t_ps **stack_a, t_ps **stack_b);
void	ps_rev_rotate(t_ps **stack);
void	ps_rev_rotate_both(t_ps **stack_a, t_ps **stack_b);
#endif
