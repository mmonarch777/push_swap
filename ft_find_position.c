/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:43:33 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 18:43:56 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_index(t_stack **stack, char *str)
{
	t_stack	*head;
	int		min;
	int		max;

	head = *stack;
	min = head->index;
	max = head->index;
	while (head)
	{
		if (min > head->index)
			min = head->index;
		if (max < head->index)
			max = head->index;
		head = head->next;
	}
	if (!ft_strncmp(str, "min", 3))
		return (min);
	return (max);
}

static void	ft_case1(t_stack **a, t_stack **b, int min, int max)
{
	t_stack	*head;
	int		last;

	head = *a;
	last = ft_last_index(a);
	while (head)
	{
		if ((*b)->index > last && (*b)->index < (*a)->index)
		{
			(*b)->num_markup = (*a)->step_up + (*b)->step_up;
			(*b)->markup = (*a)->index;
			break ;
		}
		if ((*b)->index < min || (*b)->index > max)
		{
			if (head->index == min)
			{
				(*b)->num_markup = head->step_up + (*b)->step_up;
				(*b)->markup = head->index;
				break ;
			}
		}
		head = head->next;
	}
}

static void	ft_case2(t_stack **a, t_stack **b)
{
	t_stack	*head;

	head = *a;
	while (head)
	{
		if ((*b)->index > head->index)
			break ;
		head = head->next;
	}
	while (head)
	{
		if (head->index > (*b)->index)
		{
			(*b)->num_markup = head->step_up + (*b)->step_up;
			(*b)->markup = head->index;
			break ;
		}
		head = head->next;
	}
}

static void	ft_case3(t_stack **a, t_stack **b)
{
	t_stack	*head;

	head = *a;
	while (head)
	{
		if (head->index > (*b)->index)
		{
			(*b)->num_markup = head->step_up + (*b)->step_up;
			(*b)->markup = head->index;
			break ;
		}
		head = head->next;
	}
}

void	ft_find_position(t_stack **a, t_stack **b)
{
	int	min;
	int	max;
	int	last;

	min = ft_find_index(a, "min");
	max = ft_find_index(a, "max");
	last = ft_last_index(a);
	if ((*b)->index < min || (*b)->index > max
		|| ((*b)->index > last && (*b)->index < (*a)->index))
		ft_case1(a, b, min, max);
	else if ((*b)->index < (*a)->index)
		ft_case2(a, b);
	else
		ft_case3(a, b);
}
