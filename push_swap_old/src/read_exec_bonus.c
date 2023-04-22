/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_exec_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:58:32 by mbartsch          #+#    #+#             */
/*   Updated: 2023/04/20 15:40:20 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker_bonus.h"

static void	exec_action(char *c, t_ps **stack_a, t_ps **stack_b)
{
	if (!ft_strncmp(c, "sa\n", ft_strlen(c)))
		ps_switch(stack_a);
	else if (!ft_strncmp(c, "sb\n", ft_strlen(c)))
		ps_switch(stack_b);
	else if (!ft_strncmp(c, "ss\n", ft_strlen(c)))
		ps_switch_both(stack_a, stack_b);
	else if (!ft_strncmp(c, "pa\n", ft_strlen(c)))
		ps_push(stack_b, stack_a);
	else if (!ft_strncmp(c, "pb\n", ft_strlen(c)))
		ps_push(stack_a, stack_b);
	else if (!ft_strncmp(c, "ra\n", ft_strlen(c)))
		ps_rotate(stack_a);
	else if (!ft_strncmp(c, "rb\n", ft_strlen(c)))
		ps_rotate(stack_b);
	else if (!ft_strncmp(c, "rr\n", ft_strlen(c)))
		ps_rotate_both(stack_a, stack_b);
	else if (!ft_strncmp(c, "rra\n", ft_strlen(c)))
		ps_rev_rotate(stack_a);
	else if (!ft_strncmp(c, "rrb\n", ft_strlen(c)))
		ps_rev_rotate(stack_b);
	else if (!ft_strncmp(c, "rrr\n", ft_strlen(c)))
		ps_rev_rotate_both(stack_a, stack_b);
	else
		error_h();
}

void	read_action(t_ps **stack_a, t_ps **stack_b)
{
	char	*c;

	c = get_next_line(0);
	while (c != NULL)
	{
		exec_action(c, stack_a, stack_b);
		c = get_next_line(0);
	}
}
