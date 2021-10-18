/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_markup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:45:36 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 18:45:39 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_add_mark(t_stack **head, t_stack **a, int *first_ind, int *nb)
{
	int	siz;
	int	index;

	index = *first_ind;
	siz = ft_size(a);
	if (*head == NULL)
		*head = *a;
	while (*head)
	{
		(*head)->markup = 0;
		if (*first_ind < (*head)->index)
		{
			*first_ind = (*head)->index;
			(*head)->markup = 1;
			(*nb)++;
		}
		if ((*head)->index < siz / 2 + 1 && (*head)->markup != 1 && siz > 100)
			(*head)->markup = 2;
		(*head) = (*head)->next;
		if (*head == NULL)
			*head = *a;
		if (index == (*head)->index)
			break ;
	}
}

void	ft_add_markup(t_stack **head, t_stack **a)
{
	int	nb;
	int	first_ind;

	nb = 1;
	first_ind = (*head)->index;
	(*head)->markup = 1;
	*head = (*head)->next;
	ft_add_mark(head, a, &first_ind, &nb);
	(*head)->num_markup = nb;
}

void	ft_markup(t_stack **a)
{
	t_stack	*head;

	head = *a;
	while (head)
	{
		ft_add_markup(&head, a);
		head = head->next;
	}
}
