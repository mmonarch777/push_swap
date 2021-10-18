/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:45:22 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 18:45:25 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_last_move(t_stack **a)
{
	t_stack	*head;
	int		size;

	size = ft_size(a);
	head = *a;
	ft_position(a);
	while (head)
	{
		if (head->index == 1)
			break ;
		head = head->next;
	}
	if (head->position <= size / 2 + 1)
		while (head->position != 1)
			ft_rotate("ra", a);
	else
		while (head->position != 1)
			ft_revers_rotate("rra", a);
}
