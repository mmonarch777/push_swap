/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:48:07 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 18:48:11 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_false0(t_stack **a)
{
	t_stack	*head;

	head = *a;
	while (head)
	{
		if (head->markup == 0)
			return (1);
		head = head->next;
	}
	return (0);
}

static int	ft_check_false2(t_stack **a)
{
	t_stack	*head;

	head = *a;
	while (head)
	{
		if (head->markup == 2)
			return (1);
		head = head->next;
	}
	return (0);
}

void	ft_big_markup(int index, t_stack **a)
{
	t_stack	*head;

	head = *a;
	while (head)
	{
		if (index == head->index)
			ft_add_markup(&head, a);
		head = head->next;
	}
}

static void	ft_big_sort(t_stack **a, t_stack **b)
{
	while (ft_check_false0(a))
	{
		if ((*a)->markup == 0)
			ft_push_to_stack("pb", a, b);
		else
			ft_rotate("ra", a);
	}
	while (ft_check_false2(a))
	{
		if ((*a)->markup == 2)
			ft_push_to_stack("pb", a, b);
		else
			ft_rotate("ra", a);
	}
}

void	ft_sort(t_stack **a, t_stack **b)
{
	int	index;
	int	size;

	size = ft_size(a);
	index = ft_find_start_index(a);
	ft_big_markup(index, a);
	if (size <= 100)
	{
		while (ft_check_false0(a))
		{
			if (ft_need_swap(a, index))
			{
				ft_swap("sa", a);
				ft_big_markup(index, a);
			}
			else if ((*a)->markup == 0)
				ft_push_to_stack("pb", a, b);
			else
				ft_rotate("ra", a);
		}
	}
	else
		ft_big_sort(a, b);
}
