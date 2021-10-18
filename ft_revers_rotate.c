/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revers_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:47:41 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 18:47:44 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_revers_rotate(char *str, t_stack **stack)
{
	t_stack	*swap;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	swap = *stack;
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	last = *stack;
	*stack = (*stack)->next;
	(*stack)->next = swap;
	last->next = NULL;
	if (ft_strncmp(str, "rrr", 3))
	{
		ft_printf("%s\n", str);
		ft_position(stack);
	}
}

void	ft_revers_rotate_rrr(char *str, t_stack **a, t_stack **b)
{
	ft_revers_rotate("rrr", a);
	ft_revers_rotate("rrr", b);
	ft_printf("%s\n", str);
	ft_position(a);
	ft_position(b);
}
