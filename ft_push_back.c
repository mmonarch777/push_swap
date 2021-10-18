/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:46:35 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 19:04:54 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_min_step(t_stack **head, int *min, int *index)
{
	while (*head)
	{
		if ((*head)->num_markup == *min)
			if ((*head)->index < *index)
				*index = (*head)->index;
		if (*min > (*head)->num_markup)
		{
			*min = (*head)->num_markup;
			*index = (*head)->index;
		}
		*head = (*head)->next;
	}
}

static t_stack	*ft_find_min_stepup(t_stack **b)
{
	t_stack	*head;
	int		min;
	int		index;

	head = *b;
	min = head->num_markup;
	index = head->index;
	ft_min_step(&head, &min, &index);
	head = *b;
	while (head)
	{
		if (min == head->num_markup && index == head->index)
			break ;
		head = head->next;
	}
	return (head);
}

static void	ft_make_rrr(t_stack **ha, t_stack **hb, t_stack **a, t_stack **b)
{
	if ((*hb)->position <= ft_size(b)
		/ 2 + 1 && (*ha)->position <= ft_size(a) / 2 + 1)
	{
		while ((*hb)->position != 1 && (*ha)->position != 1)
			ft_rotate_rr("rr", a, b);
		while ((*hb)->position != 1)
			ft_rotate("rb", b);
		while ((*ha)->position != 1)
			ft_rotate("ra", a);
		ft_push_to_stack("pa", b, a);
	}
	else
	{
		while ((*hb)->position != 1 && (*ha)->position != 1)
			ft_revers_rotate_rrr("rrr", a, b);
		while ((*hb)->position != 1)
			ft_revers_rotate("rrb", b);
		while ((*ha)->position != 1)
			ft_revers_rotate("rra", a);
		ft_push_to_stack("pa", b, a);
	}
}

static void	ft_no_rrr(t_stack **ha, t_stack **hb, t_stack **a, t_stack **b)
{
	if ((*hb)->position <= ft_size(b) / 2 + 1)
	{
		while ((*hb)->position != 1)
			ft_rotate("rb", b);
		while ((*ha)->position != 1)
			ft_revers_rotate("rra", a);
		ft_push_to_stack("pa", b, a);
	}
	else
	{
		while ((*hb)->position != 1)
			ft_revers_rotate("rrb", b);
		while ((*ha)->position != 1)
			ft_rotate("ra", a);
		ft_push_to_stack("pa", b, a);
	}
}

void	ft_push_back(t_stack **a, t_stack **b)
{
	t_stack	*ha;
	t_stack	*hb;
	int		sa;
	int		sb;

	sa = ft_size(a);
	sb = ft_size(b);
	ha = *a;
	hb = ft_find_min_stepup(b);
	while (ha)
	{
		if (ha->index == hb->markup)
			break ;
		ha = ha->next;
	}
	if ((hb->position <= (sb / 2 + 1) && ha->position <= (sa / 2 + 1))
		|| (hb->position > (sb / 2 + 1) && ha->position > (sa / 2 + 1)))
		ft_make_rrr(&ha, &hb, a, b);
	else
		ft_no_rrr(&ha, &hb, a, b);
}
