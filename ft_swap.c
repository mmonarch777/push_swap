/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:48:55 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 18:48:59 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(char *str, t_stack **stack)
{
	t_stack	*swap1;
	t_stack	*swap2;

	if (!*stack || !(*stack)->next)
		return ;
	swap1 = *stack;
	swap2 = (*stack)->next;
	swap1->next = swap1->next->next;
	swap2->next = swap1;
	*stack = swap2;
	if (ft_strncmp(str, "ss", 2))
	{
		ft_printf("%s\n", str);
		ft_position(stack);
	}
}

void	ft_swap_ss(char *str, t_stack **a, t_stack **b)
{
	ft_swap("ss", a);
	ft_swap("ss", b);
	ft_printf("%s\n", str);
	ft_position(a);
	ft_position(b);
}
