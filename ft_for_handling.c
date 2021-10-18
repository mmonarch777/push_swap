/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:44:15 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 18:44:19 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_duplicat(int *integer, int number)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < number)
	{
		j = i + 1;
		while (j < number)
		{
			if (integer[i] == integer[j])
				error_int("I can't work with duplicates :(", integer);
			j++;
		}
		i++;
	}
}

void	ft_check_sort(t_stack **a)
{
	t_stack	*head;
	int		numb;

	head = *a;
	numb = head->number;
	head = head->next;
	while (head)
	{
		if (numb < head->number)
			numb = head->number;
		else
			return ;
		head = head->next;
	}
	ft_clear(a);
	exit(0);
}

void	ft_clear(t_stack **a)
{
	t_stack	*head;
	t_stack	*del;
	int		size;

	head = *a;
	size = ft_size(a);
	while (size)
	{
		del = head;
		head = head->next;
		free(del);
		size--;
	}
}
