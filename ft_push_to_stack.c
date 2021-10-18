/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:47:04 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 18:47:10 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_stack(char *str, t_stack **from, t_stack **to)
{
	t_stack	*push;

	if (!*from)
		return ;
	push = *from;
	*from = (*from)->next;
	push->next = *to;
	*to = push;
	ft_printf("%s\n", str);
	ft_position(from);
	ft_position(to);
}
