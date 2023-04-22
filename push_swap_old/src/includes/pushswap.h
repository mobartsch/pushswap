/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:05:25 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/19 16:43:16 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

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
t_ps	**checker(int argc, char *argh[], t_ps **stack_a, int *sh);
int		check_sorted(t_ps **stack);
t_ps	**feed_a(t_ps **stack_a, int data, int index);
void	ps_swap(t_ps **stack);
void	ps_push(t_ps **stack_r, t_ps **stack_p);
void	ps_rotate(t_ps **stack);
void	ps_rotate_both(t_ps **stack_a, t_ps **stack_b);
void	ps_rev_rotate(t_ps **stack);
void	ps_rev_rotate_both(t_ps **stack_a, t_ps **stack_b);
#endif
