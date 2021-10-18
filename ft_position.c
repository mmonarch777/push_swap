/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:46:18 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 18:46:21 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_position(t_stack **stack)
{
	t_stack	*head;
	int		position;

	position = 1;
	head = *stack;
	while (head)
	{
		head->position = position;
		position++;
		head = head->next;
	}
}

int	ft_size(t_stack **stack)
{
	t_stack	*head;
	int		size;

	size = 0;
	head = *stack;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}

int	ft_last_index(t_stack **stack)
{
	t_stack	*head;
	int		last;

	head = *stack;
	last = 0;
	while (head)
	{
		if (head->next == NULL)
		{
			last = head->index;
			break ;
		}
		head = head->next;
	}
	return (last);
}

void	ft_step_to_up(t_stack **stack)
{
	t_stack	*head;
	int		size;

	head = *stack;
	size = ft_size(stack);
	while (head)
	{
		if ((size / 2 + 1) >= head->position)
			head->step_up = head->position - 1;
		else
			head->step_up = size - head->position + 1;
		head = head->next;
	}
}
