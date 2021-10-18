/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_need_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:45:58 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 19:14:54 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_swap(t_stack **stack)
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
}

static int	ft_find_big_num(t_stack **a)
{
	t_stack	*head;
	int		max;

	head = *a;
	max = 0;
	while (head)
	{
		if (head->num_markup > max)
			max = head->num_markup;
		head = head->next;
	}
	return (max);
}

static void	ft_add_new_markup(t_stack **a, int index)
{
	t_stack	*head;

	head = *a;
	while (head)
	{
		if (head->index == index)
			ft_add_markup(&head, a);
		head = head->next;
	}
}

int	ft_need_swap(t_stack **a, int index)
{
	t_stack	*head;
	int		num1;
	int		num2;

	head = *a;
	num1 = ft_find_big_num(a);
	ft_check_swap(a);
	ft_add_new_markup(a, index);
	num2 = ft_find_big_num(a);
	ft_check_swap(a);
	ft_add_new_markup(a, index);
	if (num2 > num1)
		return (1);
	return (0);
}

int	ft_find_start_index(t_stack **a)
{
	t_stack	*head;
	int		big;
	int		index;

	head = *a;
	big = head->num_markup;
	index = head->index;
	head = head->next;
	while (head)
	{
		if (big < head->num_markup)
		{
			big = head->num_markup;
			index = head->index;
		}
		if (big == head->num_markup)
			if (index > head->index)
				index = head->index;
		head = head->next;
	}
	return (index);
}
