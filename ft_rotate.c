/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:47:52 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 18:47:54 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(char *str, t_stack **stack)
{
	t_stack	*swap1;
	t_stack	*swap2;

	if (!*stack || !(*stack)->next)
		return ;
	swap1 = *stack;
	swap2 = (*stack)->next;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = swap1;
	swap1->next = NULL;
	*stack = swap2;
	if (ft_strncmp(str, "rr", 2))
	{
		ft_printf("%s\n", str);
		ft_position(stack);
	}
}

void	ft_rotate_rr(char *str, t_stack **a, t_stack **b)
{
	ft_rotate("rr", a);
	ft_rotate("rr", b);
	ft_printf("%s\n", str);
	ft_position(a);
	ft_position(b);
}
