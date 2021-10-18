/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:38:53 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 18:38:57 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_lstnew_ps(int number)
{
	t_stack	*stack;

	stack = malloc(sizeof (t_stack));
	if (!stack)
		return (NULL);
	stack->number = number;
	stack->next = NULL;
	return (stack);
}

void	ft_add_to_list(int *integer, int size, t_stack **a)
{
	t_stack	*head;
	int		i;

	i = 0;
	if (!*a)
	{
		*a = ft_lstnew_ps(integer[i]);
		i++;
	}
	head = *a;
	while (size > i)
	{
		head->next = ft_lstnew_ps(integer[i]);
		i++;
		head = head->next;
	}
}
